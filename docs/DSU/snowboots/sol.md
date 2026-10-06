# Đề bài:

</p>

Cho 1 mảng $H$ gồm $N$ phần tử  tượng trưng cho độ sâu của tuyết , và có $B$ đôi giày có 2 thông số $s$ và $d$:

* $s_i$ là độ sâu tuyết lớn nhất mà đôi giày này có thể dùng để đi qua
* $d_i$ là quãng đường mà chúng ta có thể đi xa nhất từ vị trí hiện thời

Ta phải kiểm tra xem với mỗi đôi giày thì ta có thể đi từ 1 đến $N$ không.

## Giới hạn:

$N , B <= 2*10^5$

$H_i , s_i <= 10^9$

$d_i <= N-1$

## Lời giải:

Ta để ý 1 tính chất như sau: Khi có 1 đoạn liên tiếp các ô tuyết mà ta không thể đi qua bằng đôi giày hiện thời(hay là $H_j > s_i$) có độ dài $>=D$ thì ta chắc chẵn sẽ không thể đi qua được

Do đó ta sẽ tìm cách để lưu các khoảng liên tiếp này

Để lưu các khoảng liên tiếp thì ta có thể sử dụng $DSU$ kết hợp với là set lưu kích cỡ các phần tử(hay là khoảng) liên tiếp

Chi tiết thì ta sẽ làm như sau:
* Đầu tiên ta sắp xếp các đôi giày theo $s_i$ giảm dần thì khi đó ta sẽ có thể chỉ cần thêm các vị trí có $H_i > s_{hiện thời}$

* Mỗi khi ta thêm thì ta kiểm tra 2 vị trí bên xem là 2 vị trí này đã được "thêm" vào chưa và dựa vào đó ta quyết định xem có nên tạo cạnh giữa 2 vị trí này hay ko

* Khi ta thêm cạnh vào thì ta cùng lúc sẽ cập nhật set quản lý kích cỡ các thành phần liên thông

* Cuối cùng ta kiểm tra xem có phần tử nào trong set mà $ >= d_i$ hay không

Thực chất thay vì sử dụng 1 cái set, ta có thể chỉ cần sử dụng 1 biến $max$ để quản lý phần tử liên thông lớn nhất thôi.

Khi đó ta sẽ giảm được thêm $O(logn)$ của set.

Độ phức tạp của cách làm này khi đó sẽ là:

$O(n * \alpha(n))$

