# Rubric — Week 4 / Ex3

| Phần | Trọng số | Đạt điểm khi |
|---|---|---|
| Số đo CPU%/stack | **35%** | Bảng số liệu thật từ `vTaskGetRunTimeStats`/`uxTaskGetStackHighWaterMark`, đọc được từ ảnh UART log |
| Số đo latency worst-case | **35%** | Ảnh logic analyzer đo đúng điều kiện tải cao nhất, có tạo tải nhiễu thật sự |
| Phân tích | **20%** | Kết luận đạt/không đạt deadline có căn cứ; nếu không đạt, chỉ đúng nguyên nhân |
| Vấn đáp | **10%** | Giải thích được cách tạo tải cao nhất và vì sao đó là worst-case |

## Trượt ngay nếu
- Đo ở điều kiện tải rảnh rồi báo cáo như worst-case.
- Số liệu CPU%/stack không khớp với log UART đính kèm (nghi ngờ bịa số).
- `PREDICTION.md` commit sau khi đo.
