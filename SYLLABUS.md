# Syllabus – Kế hoạch chi tiết 4 tuần

## W1.1 – Bring-up: CubeMX (CMake) + FreeRTOS thủ công
- **Nội dung:** CubeMX sinh project CMake KHÔNG có middleware FreeRTOS; thêm FreeRTOS-Kernel bằng add_subdirectory; viết FreeRTOSConfig.h; HAL timebase sang TIM4; map SVC/PendSV/SysTick handler.
- **API bắt buộc:** xTaskCreate, vTaskStartScheduler, vTaskDelay, configASSERT
- **Tài liệu:** Mastering ch.1–2; tài liệu CMake của FreeRTOS-Kernel
- **Output:** CMake build + nạp được, 1 task nháy LED; SETUP.md tự viết các bước + 2 lỗi đã gặp.
- **Tiêu chí đạt:** Giải thích được vì sao phải nhường SysTick và vì sao không dùng HAL_Delay trong task.
- **Giờ:** 3

## W1.2 – Task, priority, preemption
- **Nội dung:** 3 task toggle 3 GPIO, priority + chu kỳ theo MSSV (params.h). Thêm task busy-loop priority cao để quan sát starvation.
- **API bắt buộc:** xTaskCreate, vTaskDelay, taskYIELD, vTaskPrioritySet
- **Tài liệu:** Mastering ch.4
- **Output:** PREDICTION.md (timeline vẽ tay TRƯỚC khi chạy) + ảnh logic analyzer + giải thích chỗ lệch.
- **Tiêu chí đạt:** Dự đoán đúng thứ tự chạy; giải thích starvation bằng ảnh đo.
- **Giờ:** 3

## W1.3 – Timing & jitter
- **Nội dung:** So sánh vTaskDelay và xTaskDelayUntil khi thời gian xử lý thay đổi; đổi configTICK_RATE_HZ (100 / 1000) và đo lại.
- **API bắt buộc:** xTaskDelayUntil, xTaskGetTickCount, pdMS_TO_TICKS
- **Tài liệu:** Mastering ch.4
- **Output:** Bảng jitter (min/max/TB, ≥100 mẫu) cho 4 cấu hình + ảnh đo.
- **Tiêu chí đạt:** Kết luận dựa trên số đo của chính mình.
- **Giờ:** 3

## W1.4 – Ngân sách bộ nhớ (20 KB RAM)
- **Nội dung:** Đo stack high-water-mark, free heap; configCHECK_FOR_STACK_OVERFLOW=2 + hook; cố ý gây overflow; thử xTaskCreateStatic.
- **API bắt buộc:** uxTaskGetStackHighWaterMark, xPortGetFreeHeapSize, vApplicationStackOverflowHook, xTaskCreateStatic
- **Tài liệu:** Mastering ch.3
- **Output:** Bảng RAM budget + log overflow hook + lý do chọn stack size.
- **Tiêu chí đạt:** Tổng RAM khớp file .map; giải thích heap_4 khác heap_1.
- **Giờ:** 2

## W2.1 – Queue: pipeline cảm biến
- **Nội dung:** MPU6050 (HAL I2C) → task đọc → queue → task lọc → queue → task in UART. Kích thước queue + tần số theo MSSV.
- **API bắt buộc:** xQueueCreate, xQueueSend, xQueueReceive, uxQueueMessagesWaiting
- **Tài liệu:** Mastering ch.5
- **Output:** Code + đồ thị độ đầy queue theo thời gian + giải thích khi nào queue đầy.
- **Tiêu chí đạt:** Tính trước kích thước queue tối thiểu và kiểm chứng bằng đo.
- **Giờ:** 3

## W2.2 – Race condition & mutex
- **Nội dung:** Nhiều task cùng printf ra UART → lẫn lộn. Sửa bằng mutex, critical section, gatekeeper task; so sánh.
- **API bắt buộc:** xSemaphoreCreateMutex, xSemaphoreTake/Give, taskENTER_CRITICAL/EXIT
- **Tài liệu:** Mastering ch.8
- **Output:** Log lỗi trước khi sửa + bảng so sánh 3 cách.
- **Tiêu chí đạt:** Tái hiện lỗi ổn định trước khi sửa.
- **Giờ:** 3

## W2.3 – Priority inversion
- **Nội dung:** 3 task L/M/H dùng chung tài nguyên: binary semaphore (inversion) vs mutex (inheritance). Đo thời gian H bị block.
- **API bắt buộc:** xSemaphoreCreateBinary, xSemaphoreCreateMutex, uxTaskPriorityGet
- **Tài liệu:** Mastering ch.8
- **Output:** 2 ảnh logic analyzer trước/sau + số đo thời gian block.
- **Tiêu chí đạt:** Chỉ ra đúng thời điểm inversion trên ảnh đo.
- **Giờ:** 3

## W2.4 – Event group & task notification
- **Nội dung:** Đồng bộ 3 task bằng event group; thay 1 semaphore bằng notification, so sánh RAM và tốc độ.
- **API bắt buộc:** xEventGroupSetBits, xEventGroupWaitBits, xTaskNotifyGive, ulTaskNotifyTake
- **Tài liệu:** Mastering ch.9–10
- **Output:** Bảng so sánh RAM + thời gian (DWT cycle).
- **Tiêu chí đạt:** Nêu được khi nào KHÔNG dùng được notification.
- **Giờ:** 2

## W3.1 – Ngắt → task, NVIC priority
- **Nội dung:** EXTI nút nhấn đánh thức task. Cố ý đặt priority ngắt cao hơn configMAX_SYSCALL_INTERRUPT_PRIORITY → quan sát assert. Đo latency ISR→task.
- **API bắt buộc:** vTaskNotifyGiveFromISR, xSemaphoreGiveFromISR, portYIELD_FROM_ISR
- **Tài liệu:** Mastering ch.7; 'RTOS for ARM Cortex-M'
- **Output:** Ảnh đo latency có/không portYIELD_FROM_ISR + giải thích assert.
- **Tiêu chí đạt:** Giải thích đúng quan hệ số priority NVIC và cấu hình.
- **Giờ:** 3

## W3.2 – Software timer & debounce
- **Nội dung:** Debounce bằng one-shot timer; thêm auto-reload timer; thử callback có block.
- **API bắt buộc:** xTimerCreate, xTimerStart/Reset, xTimerResetFromISR
- **Tài liệu:** Mastering ch.6
- **Output:** Ảnh đo nảy phím trước/sau + giải thích daemon task.
- **Tiêu chí đạt:** Giải thích vì sao callback không được block.
- **Giờ:** 2

## W3.3 – UART RX → stream buffer → parser
- **Nội dung:** Ngắt UART RX đẩy byte vào stream buffer; parser đổi chu kỳ/priority/suspend task lúc runtime.
- **API bắt buộc:** xStreamBufferCreate, xStreamBufferSendFromISR, xStreamBufferReceive, vTaskSuspend/Resume
- **Tài liệu:** Mastering (Stream Buffers)
- **Output:** Demo bộ lệnh + test gửi nhanh, báo cáo có mất byte không.
- **Tiêu chí đạt:** Không mất byte ở baud theo MSSV.
- **Giờ:** 3

## W3.4 – Debug: CPU load, deadlock, watchdog
- **Nội dung:** Run-time stats bằng DWT CYCCNT; tìm deadlock trong code lỗi mentor cài sẵn; task giám sát + IWDG.
- **API bắt buộc:** vTaskGetRunTimeStats, uxTaskGetSystemState, xEventGroupWaitBits
- **Tài liệu:** Mastering (Run-time stats); RM0008 (IWDG)
- **Output:** Bảng CPU % + báo cáo nguyên nhân deadlock có bằng chứng + demo watchdog reset.
- **Tiêu chí đạt:** Tìm ra deadlock bằng công cụ, không đoán.
- **Giờ:** 3

## W4.1 – Thiết kế mini project
- **Nội dung:** Data logger MPU6050, tần số lấy mẫu + deadline ISR→xử lý theo MSSV.
- **API bắt buộc:** Tự chọn (chỉ API gốc)
- **Tài liệu:** Tổng hợp tuần 1–3
- **Output:** Design doc 2–3 trang: task diagram, lý do chọn priority, timing + RAM budget. Mentor duyệt trước.
- **Tiêu chí đạt:** Timing budget có số liệu.
- **Giờ:** 3

## W4.2 – Hiện thực
- **Nội dung:** Code theo design; check_api.sh sạch; AI_LOG.md đầy đủ.
- **Output:** Repo hoàn chỉnh.
- **Tiêu chí đạt:** Build CMake sạch, không CMSIS-OS.
- **Giờ:** 5

## W4.3 – Đo & chứng minh
- **Nội dung:** Đo worst-case latency, CPU load, stack HWM khi tải cao nhất.
- **API bắt buộc:** vTaskGetRunTimeStats, uxTaskGetStackHighWaterMark
- **Output:** Bảng kết quả + ảnh đo chứng minh đạt deadline.
- **Tiêu chí đạt:** Đạt deadline ở worst-case.
- **Giờ:** 2

## W4.4 – Bảo vệ
- **Nội dung:** 10 phút + mentor đổi 1 thông số tại chỗ; SV dự đoán rồi chạy.
- **Output:** Buổi bảo vệ.
- **Tiêu chí đạt:** Dự đoán hợp lý, giải thích được kết quả.
- **Giờ:** 1

## Rubric
- 1 | Task, timing, bộ nhớ | 20%
- 2 | Đồng bộ & IPC | 25%
- 3 | Ngắt, timer, debug | 25%
- 4 | Mini project + bảo vệ | 30%
- Code | Đúng API gốc, chạy được, code sạch | 30%
- Số đo + báo cáo | PREDICTION.md, ảnh đo, REPORT.md, giải thích chỗ lệch | 40%
- Vấn đáp | Trả lời câu hỏi + xử lý thay đổi tại chỗ | 30%
- Ngưỡng đạt (thang 10) |  | 6.5
- Điểm liệt: Dùng CMSIS-OS → phần code bài đó = 0. Không có AI_LOG.md hoặc không giải thích được code tự nộp → phần vấn đáp = 0.
