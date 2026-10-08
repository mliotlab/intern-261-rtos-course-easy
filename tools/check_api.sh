#!/usr/bin/env bash
# Fail if any CMSIS-RTOS wrapper API shows up in student code.
# Native FreeRTOS API only. Usage: ./tools/check_api.sh [path ...]
#
# Comments are stripped before matching, so prose like "cmsis_os.h is forbidden"
# in a header comment does not trip the check — only real code does.
set -uo pipefail

PATTERN='cmsis_os|osThread|osDelay|osMessageQueue|osMutex|osSemaphore|osEventFlags|osTimer|osKernel'

TARGETS=("$@")
if [ ${#TARGETS[@]} -eq 0 ]; then
  TARGETS=(week1 week2 week3 week4)
fi

EXISTING=()
for t in "${TARGETS[@]}"; do
  [ -e "$t" ] && EXISTING+=("$t")
done
if [ ${#EXISTING[@]} -eq 0 ]; then
  echo "check_api: no target paths found, nothing to check"
  exit 0
fi

mapfile -d '' FILES < <(find "${EXISTING[@]}" -type f \
  \( -name '*.c' -o -name '*.h' -o -name '*.cpp' \) -print0)

if [ ${#FILES[@]} -eq 0 ]; then
  echo "check_api: no C/C++ sources found, nothing to check"
  exit 0
fi

strip_comments() {
  # Blank out comment bodies but keep line numbering intact.
  python3 - "$1" <<'PY'
import re, sys
src = open(sys.argv[1], encoding="utf-8", errors="replace").read()
src = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), src, flags=re.S)
src = re.sub(r"//[^\n]*", "", src)
sys.stdout.write(src)
PY
}

found=0
for f in "${FILES[@]}"; do
  if hits=$(strip_comments "$f" | grep -nE "$PATTERN"); then
    found=1
    while IFS= read -r line; do
      echo "$f:$line"
    done <<<"$hits"
  fi
done

mkfail=0
# CMake only: no hand-written Makefiles anywhere in student code
if mk=$(find "${EXISTING[@]}" \( -name Makefile -o -name '*.mk' \) -not -path '*/build/*' | grep .); then
  echo "$mk"
  echo "check_api: FAIL — Makefile detected (build bang CMake)."
  mkfail=1
fi

if [ "$found" -eq 1 ]; then
  echo
  echo "check_api: FAIL — CMSIS-RTOS API detected above."
  echo "Chi duoc dung API goc cua FreeRTOS (task.h, queue.h, semphr.h, ...)."
  exit 1
fi

[ "$mkfail" -ne 0 ] && exit 1
echo "check_api: PASS — native FreeRTOS API only. (${#FILES[@]} files)"
