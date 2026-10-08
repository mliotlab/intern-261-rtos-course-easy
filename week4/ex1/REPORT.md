# Report — Week 4 / Ex1 (Design doc)

`student_id`: ______    Commit của PREDICTION.md: ______

> File này ĐÓNG VAI TRÒ design doc 2–3 trang nộp cho mentor duyệt trước khi
> viết code. Điền đủ số liệu — không mô tả chung chung.

## 1. Task diagram
Mô tả (sơ đồ ASCII hoặc ảnh chèn vào) luồng: ISR lấy mẫu MPU6050 → hàng đợi
→ task xử lý → task ghi UART. Ghi rõ priority từng task.

## 2. Timing budget
| Đại lượng | Công thức / nguồn số liệu | Giá trị |
|---|---|---|
| Chu kỳ lấy mẫu | 1 / `SAMPLE_RATE_HZ` | |
| Latency ISR→task (đo thật, week3/ex1) | | |
| Thời gian xử lý 1 mẫu (ước lượng) | | |
| Tổng so với `ISR_TO_PROC_DEADLINE_US` | | Đạt / Không đạt |

## 3. RAM budget
| Thành phần | Kích thước | Ghi chú |
|---|---|---|
| Queue (độ dài × cỡ phần tử) | | |
| Stack task lấy mẫu | | |
| Stack task xử lý | | |
| Stack task ghi UART | | |
| **Tổng** | | So với `MAX_HEAP_BYTES` |

## 4. Lựa chọn API đồng bộ
Queue / event group / stream buffer — vì sao chọn cái này cho pipeline này.

## 5. Xử lý khi hàng đợi đầy
Drop mẫu mới hay mẫu cũ? Có đếm số mẫu bị rớt để báo cáo ở ex3 không?

## 6. Mentor duyệt
Chữ ký / ghi chú của mentor sau buổi duyệt thiết kế: ______
