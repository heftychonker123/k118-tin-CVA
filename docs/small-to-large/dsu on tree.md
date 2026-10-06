# Bài toán khởi đầu:

</p> Cho 1 cây n đỉnh gốc tại 1, mỗi đỉnh có 1 màu c, với mỗi đỉnh tìm số lượng màu phân biệt ở cây con của đỉnh đó

## Giới hạn:
* $n <= 3 * 10^5$
* $c <= 10^6$
</p>

</p>


# Thuật toán trâu
Ta có thể xét trâu từng subtree của các cây và đếm số lượng các giá trị phân biệt

Cách làm này sẽ có độ phức tạp là $ O(n^2)$, chắc chẵn sẽ bị TLE
</p>

</p> 

# Thuật toán cải thiện

Thay vào đó, ta có thể lấy tập tất cả các phần tử phân biệt của các cây con của node hiện thời là u và sử dụng kỹ thuật small-to-large để merge 
lại

Độ phức tạp của cách làm này sẽ là $O(nlog^2(n))$


## Phân tích:

* Ta thấy rằng, 1 node chỉ có thể được merge vào O(log(n)) lần, do mỗi lần merge từ nhỏ -> lớn thì kích cỡ của set hiện thời chứa node này tăng lên 2

* Mỗi lần insert tốn chi phí $O(log(n))$

$=>$ Chi phí tổng sẽ là $O(nlog^2(n))$


</p>

</p>

# Thuật toán chuẩn

Ta mong muốn tìm 1 cách để gỡ đi cái $O(log(n))$ mỗi lần insert kia

Để làm điều này ta sẽ sử dụng kỹ thuật **DSU on Tree**:
* Đầu tiên ta giải bài toán này cho tất cả cây con của node u hiện thời mà không phải là cây con lớn nhất của u , rồi ta xóa đị cây con này
* Ta giải cho cây con lớn nhất của con của u
* Ta thêm u vào và giải truy vấn tại u

Cấu trúc dữ liệu cho kỹ thuật này thì phụ thuộc vào từng bài, nhưng ở đây việc dùng set là quá mức.

Thay vào đó, ta sẽ chỉ cần lưu trữ mảng đếm $cnt$ và biến $distinct$ lưu các giá trị phân biệt.

Khi ta cập nhập mảng đếm thì ta cùng lúc sẽ cập nhập biến distinct này luôn. Khi đó mỗi lần cập nhật(hay là insert) sẽ chỉ mất O(1) thôi
## Phân tích

* Về mặt bản chất thuật toán này cũng chả khác gì thuật toán ở trên cả( thuật $O(nlog^2n)$) nhưng do insert giờ chỉ tốn $O(1)$ thôi nên ta sẽ có độ phức tạp chuẩn là $O(nlog(n))$
</p>