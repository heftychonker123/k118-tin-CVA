# Đề bài


Cho 1 mảng $a_i$ gồm m giá trị trong từ 1 -> $n$ , và 1 hoán vị $p$ kích thước $n$.

Một hoán vị vòng của p là 1 cyclic shift của $p$

Cho $q$ truy vấn ${l,r}$ , ta phải kiểm tra xem có 1 dãy con của mảng $a_{l -> r}$ là 1 hoán vị vòng của $p$ không.

## Giới hạn:
$n,m,q <= 2 * 10 ^ 5$

# Lời giải:

Lưu với mỗi giá trị $t$: giá trị trước nó trong hoán vị $p$ , gọi là $prev_t$ . Với trường hợp giá trị $t$ là đầu tiên của $p$ thì $prev_t$ = $p_{last}$

Ta lưu thêm với mỗi vị trí $i$ trong $a$ 1 giá trị nữa là $prevPos_i$ là vị trí bên trái i lớn nhất thỏa mãn $a_j = prev_{a_i}$

Ta thấy rằng đoạn $a_{l -> r}$ chỉ thỏa mãn điều kiện có dãy con độ dài n khi tồn tại 1 vị trí $i$ mà sao cho khi ta di chuyển từ $i -> prevPos_i$ liên tục $n-1$ lần thì vị trí kết thúc vẫn sẽ $\ge l$

Tính toán với mỗi giá trị vị trí $i$ vị trí sau khi nhảy $i -> prevPos_i$ liên tục $n - 1$ lần. Sử dụng binary lifting để tính cái này -> $O(log(n))$ với mọi giá trị $i : 1 -> m$. Gọi giá trị này là $j_i$

Khi đó giờ ta sẽ quy bài toán về việc tìm max $j_i$ cho các giá trị $i : l -> r$ -> Segment Tree/ RMQ $O(1)$.

Độ phức tạp là $O(mlogn + qlogm)$ / $O(mlogn + q)$



