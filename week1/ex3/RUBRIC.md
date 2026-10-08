# Rubric — Week 1 / Ex3

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Code | **30%** | `check_api.sh` = 0, tải giả lặp lại được (seed cố định), kiểm tra giá trị trả về của `xTaskDelayUntil`, không hard-code số tick |
| Số đo phần cứng | **30%** | 4 cấu hình × 5 đại lượng tính từ CSV thật, có CSV + script commit kèm, 4 ảnh zoom thấy được jitter |
| Giải thích | **25%** | Công thức drift có `WORK_JITTER_US` của mình và khớp số đo; giải thích đúng sai số làm tròn ở 100 Hz |
| Vấn đáp | **15%** | Bảng overhead tick 100 vs 1000 Hz đo thực; bảo vệ được lựa chọn tick rate bằng số của mình |

Code tối đa 30%. Số đo + giải thích + vấn đáp = 70%.

## Trượt ngay nếu
- Có `cmsis_os*` / `os*` trong code.
- `PREDICTION.md` commit sau khi nạp chương trình.
- Thống kê đọc tay thay vì tính từ CSV, hoặc không commit CSV.
- Drift của `xTaskDelayUntil` báo là 0 tròn mà không có số liệu.
