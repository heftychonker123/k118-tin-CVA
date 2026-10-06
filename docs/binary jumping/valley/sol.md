# Đề bài:

Cho 1 cây gồm $n$ đỉnh, trong đó có $s$ đỉnh được đánh dấu và 1 đỉnh đặc biệt $E$. 

Cho $q$ truy vấn , ta cần biết rằng khi ta xóa cạnh thứ $i$ thì ta từ node $R$ có thể đi đến node $E$ hay không, mà nếu không thể thì node được đánh dấu gần nhất cách $R$ bao nhiêu?

## Giới hạn

$1 <= s <= n <= 10^5$

$q <= 10^5$

# Lời giải

Bài toán này được chia thành 2 phần:

* Ta có thể đi đến node $E$ hay không?

* Node được đánh dấu gần $R$ nhất là gì?


## Vấn đề đầu tiên
Xét cạnh $i: A - B$, không mất tính tổng quát giả sử $B$ là con của $A$.

Ta có: $R$ đến được $E$ khi và chỉ khi:

* $R,E$ cùng thuộc subtree của $B$
* $R,E$ cùng ko thuộc subtree của $B$

Nếu ta đặt E là node gốc của cây thì ta sẽ có điều kiện mới là $R$ phải ko thuộc subtree của $B$ thôi!

## Vấn đề số hai

Giờ ta phải tìm node được đánh dấu gần $R$ nhất trong subtree $B$.

Ta có công thức sau cho hàm $dist(u,v)$:

$$dist(u,v) = depth(u) + depth(v) - 2 * depth(lca(u,v))$$

giả sử với node $R$ ta không biết node dược đánh dấu gần nhất với nó là node nào, nhưng ta biết LCA của 2 node này là $u$:

$$minDist = depth(R) - 2*depth(u) + min_{i \in marked}depth(i)$$

Ta sẽ tính với mỗi node $v$ hàm magic như sau:

$$magic(v) = min_{i \in marked}depth(i) - 2 * depth(v)$$

Khi đó ta sẽ phải lấy với mỗi tổ tiên $u$ của node $R$: $min(magic(u))$

Ta có thể sử dụng kỹ thuật binary lifting để tính toán cái này:

Độ phức tạp sẽ là $O(qlog(n) + nlog(n))$