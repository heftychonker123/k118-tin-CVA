# Bài toán:

Cho 1 cây gồm $n$ đỉnh và giá trị $k$ nguyên dương, bài toán yêu cầu ta đếm số đường đi có đúng độ dài là $k$

## Giới hạn:

$ 1 <= k <= n <= 2 * 10^5$

# Lời giải 1: Centroid Decomposition

Ta sẽ giải quyết bài toán này sử dụng kỹ thuật **Centroid Decomposition**.

Chi tiết hơn, ta để ý rằng với mỗi đỉnh $i$, ta có thể phân loại các đường đi thành 2 dạng là đi qua $i$ và không đi qua

Do đó , với mỗi cây hiện thời, ta sẽ chỉ xử lý bài toán như sau: Có bao nhiêu đường đi độ dài k đi qua $c$? ($c$ là trọng tâm của cây hiện thời)

Ta có thể giải quyết bài toán như sau:

* Duy trì 1 mảng đếm $cnt_i$

* Với mỗi con của $c$, ta tính khoảng cách của các node trong cây con của node đó với $c$.

* 2 đỉnh có đường đi đi qua $c$ và cách nhau $k$ khi và chỉ khi 2 đỉnh này thuộc 2 cây con của con $c$ khác nhau và $depth_i + depth_j = k$

Độ phức tạp của cách làm này sẽ là $O(n)$

=> Tổng độ phức tạp sẽ là $O(nlog(n))$

Chi tiết hơn:

* Do chi phí của việc tạo mảng hiệu mới mỗi lần **rất cao** nên thay vào đó ta sẽ phải sử dụng 1 mảng đếm global + rollback

* Bên cạnh đó, việc dfs nhiều lần cũng có thể tốn rất nhiều thời gian và bộ nhớ, nên do đó ta sẽ chỉ dfs 1 lần để tính $depth_i$ và lưu các node thuộc cây con để giảm tgian phải dùng cho dfs đi

# Lời giải 2: Small to Large

Sử dụng 1 phần tư tưởng của cách làm 1 ta cũng có cách làm sau bằng kỹ thuật **Small to Large**:

Với mỗi node thì ta sẽ tìm số đường đi có độ dài bằng k mà đi qua node này

Ta có đường đi từ đỉnh $a->b$ sẽ đi qua node $i$ hiện thời khi và chỉ khi

* Giả sử $a$ thuộc cây con node $x$ với $x$ là con của $i$ . Tương tự thế, ta cũng giả sử $y$ luôn cho $b$. Khi đó: $x \ne y$

* $depth_a + depth_b - 2depth_i = k$ hay $depth_a + depth_b = 2depth_i + k$

Với mỗi node, ta sẽ lưu 1 map chứa các giá trị $depth$ ở trong subtree của nó

Khi đó, ta sẽ merge small-to-large để tìm từng giá trị này và cùng lúc đếm số lượng đường đi thỏa mãn 2 điều kiện ở trên.

Độ phức tạp của cách làm này sẽ là $O(nlog^2n)$

# Lời giải 3: Small to Large cải tiến

Ta sẽ thay thế cái map lời giải trên bằng 1 cái deque.
