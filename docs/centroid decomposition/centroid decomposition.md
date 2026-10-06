# Phân tích chia để trị:

Chia để trị về mặt bản chất là chia nhỏ 1 vấn đề thành các vấn đề nhỏ hơn và gộp các lời giải này với nhau.

Với hầu hết các vấn đề DNC trên mảng thì ta sẽ chia đôi mảng. Vậy ta có cách nào để tiến hành quá trình này trên cây?

# Trọng tâm của cây:

Trọng tâm của cây được định nghĩa là điểm thỏa mãn khi ta đặt gốc của cây ở đây thì tất cả các cây con sẽ có kích cỡ bé hơn $N/2$ (với $N$ là kích cỡ của cây)

Thuật toán tìm trọng tâm như sau:

* Xét tất cả các con của node i hiện thời

* Nếu tất cả các con j của i có $|subtree_j| <= N/2$ thì đây đã là centroid rồi

* Không thì ta di chuyển sang con đầu tiên có $|subtree_j| > N/2$

# Liên hệ với chia để trị:

Ta để ý rằng, chính vị trí centroid của cây hiện thời này không khác gì với vị trí trung điểm của mảng khi ta chia vấn đề trong DNC thông thường. 

Do đó ta có thể tiến hành chia để trị bằng cách là lần lượt cắt cây ban đầu thành các cây con khi ta đặt gốc là centroid.

Độ phức tạp của việc chia này sẽ là $O(nlogn)$

# Độ phức tạp của thuật centroid decomposition:

Ta có thể phân tích độ phức tạp trong TH xấu nhất là khi centroid tách cây hiện thời thành 2 cây có kích thước $n/2$

Giả sử giải bài toán trong cây hiên thời mất độ phức tạp là $S(n)$ thì ta sẽ có công thức truy hồi sau:

$T(n) = 2 * T(n/2) + S(n)$

Giải công thức truy hồi này ta sẽ có độ phúc tạp của thuật toán này trong TH xấu nhất sẽ là:

$T(n) = O(S(n) * log(n))$

