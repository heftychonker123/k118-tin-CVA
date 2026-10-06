# Bài toán:

Cho 1 cây gồm $N$ đỉnh , tương ứng với mỗi đỉnh là 1 trọng số $a_i$. 

Với mỗi đỉnh $i$, ta được yêu cầu phải tìm độ dài dãy con tăng dài nhất của tập trọng số các đỉnh trên đường đi từ 1 đến $i$.

## Giới hạn:
$N <= 2 * 10^5$

$a_i <= 10 ^ 9$

# Lời giải trâu:

Ta lấy tập các giá trị từ 1 -> đỉnh $i$ bằng DFS, rồi ta chạy thuật toán LIS ở trên tập đó

Độ phức tạp thời gian sẽ là: $O(n^2logn)$
Còn kgian thì sẽ là $O(n^2)$

# Tối ưu hóa đầu tiên

Trước hết ta sẽ đặt $dp_i$ là dãy con tăng dài nhất của các trọng số từ 1 đến $i$ mà kết thúc tại $i$

Khi đó ta sẽ có thể xét các tổ tiên của $i$ để xem có ai có thể "kéo dài" cái LIS kết thúc tại $i$ không:

$dp_i = max_{j \in parent_i , a_j < a_i}(dp_j + 1) $   

Độ phức tạp thời gian sẽ là $O(n^2)$ , không gian là $O(n)$

# Tối ưu hóa tiếp theo

Ta sẽ phải tối ưu hóa lời giải này xuống $O(nlogn)$ hoặc $O(nlog^2n)$

Ta sẽ phải tìm cách để lấy được $dp_i$ của các cha nhanh chóng

Để làm được điều này ta có thể cân nhắc sử dụng **Segment Tree** có chức năng rollback.

Chi tiết như sau:

* Ta sẽ duy trì 1 segment tree lưu giá trị dp lớn nhất với từng trọng số

* Khi ta sẽ đến đỉnh i, ta sẽ tính $dp_i$ sử dụng cái segment tree này(Tương tự LIS thông thường)

* Ta sẽ lại đi xuống mỗi con của i để tính dp của chúng

* Cuối cùng là ta sẽ "hủy" cái cập nhật ở vị trí $a_i$ trong segment tree sử dụng rollback. Đây là vì khi ta hủy cập nhật này, đây sẽ là cập nhật cuối cùng nên chỉ cần rollback lại các node trên segment tree bị ảnh hưởng lại về trước khi ta cập nhật là ok.

Độ phức tạp của cách tính dp này sẽ là (nếu như t nghĩ) sẽ là O(nlog(n)) bởi vì:

* Tính $dp_i$ tốn $O(logn)$
* Cập nhật vị trí $a_i$ mất $O(log)$
* Rollback mất $O(logn)$ vì cập nhật chỉ ảnh hưởng $O(logn)$ node thôi.

Bộ nhớ thì sẽ là $O(nlog(n))$ để lưu mảng rollback(chính xác là vì chỉ có $O(nlogn)$ cập nhật), $O(n)$ để lưu segment tree và $O(n)$ để dfs.

## Vấn đề cuối: 
Giờ ta tính LIS tập trọng số các đỉnh trên đường đi từ 1 đến $i$ như thế nào?

Ta dfs trên cây và với mỗi đỉnh $i$:

$res_i = max(dp_i , res_j)$ với j là cha của i.

# P/s:

Thực chất cũng có 1 lời giải O(nlog(n)) ngắn hơn rất nhiều nhưng bộ nhớ tận O(n^2) nên thôi.

Ta sẽ sử dụng chuẩn thuật toán O(nlog(n)) cho việc tìm LIS mở rộng cho cây.

Khi ta di chuyển từ đỉnh $i$ xuống con của nó, ta truyền luôn cái mảng $dp$ hiện thời(dp ở đây != với dp được định nghĩa ở trên).

Rồi ta chạy như tìm LIS thông thường.
Kết quả LIS ở đỉnh i sẽ là kích cỡ mảng dp lúc đó

Thực chất ta có thể làm rollback như trên nhưng lười quá nên thôi =).


# p/s 2:

Bài này cái chính đó là tìm cách để duy trì thông tin liên quan đến các tổ tiên của node $i$ thôi nên có thể có rất nhiều cách(chẳng hạn như cách segment tree ở trên hoặc cách binary search LIS như đã nói trong p/s 1).

# p/s 3:

T chưa thử kem đánh răng p/s bao giờ btw

# p/s 4:

Dm t ghét số lớn

