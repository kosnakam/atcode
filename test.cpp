#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 探索する状態を定義
struct State {
    long long cost; // 現在の合計コスト（最大値からの減少分）
    int idx;        // 最後に加算（または置換）したコスト配列Dのインデックス
    int count;      // 現在変更しているクッキーの枚数

    // Min-Heap のため、コストが小さい方が優先度が高い（topに来る）ように定義
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int main() {
    // 入出力の高速化
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K, X;
    if (!(cin >> N >> K >> X)) return 0;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // 美味しさの降順にソート（A[0]が最も美味しい）
    sort(A.rbegin(), A.rend());

    // 最大の美味しさ（全てA[0]を選んだ場合）
    long long maxSum = (long long)K * A[0];

    // 「A[0]を選ぶ代わりにA[i]を選んだ時の損失（コスト）」を計算
    // Aは降順なので、D[i] >= 0 となる
    vector<long long> D;
    for (int i = 1; i < N; ++i) {
        D.push_back(A[0] - A[i]);
    }

    // コストが小さい順にソート
    sort(D.begin(), D.end());

    // まず最大値（コスト0）を出力
    cout << maxSum << "\n";
    X--; 

    // クッキーの種類が1つしかない(N=1)、または1つ出力して終わりの場合
    if (D.empty() || X == 0) return 0;

    // 優先度付きキュー（小さいコストを優先）
    priority_queue<State, vector<State>, greater<State>> pq;

    // 初期状態：最もコストが低い変更を1つ行う
    // クッキーを少なくとも1枚変更できる場合のみ追加 (K >= 1)
    if (K >= 1) {
        pq.push({D[0], 0, 1});
    }

    while (X > 0 && !pq.empty()) {
        State current = pq.top();
        pq.pop();

        // 答えを出力（最大値 - 現在のコスト）
        cout << (maxSum - current.cost) << "\n";
        X--;

        // 次の遷移 1: 【追加】
        // 同じ種類の変更をもう1つ追加する
        // 例: 直前にA[0]->A[i]を変えたが、さらにもう1枚 A[0]->A[i] を行う
        // 変更枚数が K 枚以下でなければならない
        if (current.count + 1 <= K) {
            pq.push({current.cost + D[current.idx], current.idx, current.count + 1});
        }

        // 次の遷移 2: 【置換】
        // 最後に加えた変更を、次の大きさのコストのものに変える（シフトする）
        // 例: 直近の変更 A[0]->A[i] を取り消して、代わりに A[0]->A[i+1] にする
        // これは「変更枚数」は増えないので、Kのチェックは不要
        if (current.idx + 1 < (int)D.size()) {
            pq.push({current.cost - D[current.idx] + D[current.idx + 1], current.idx + 1, current.count});
        }
    }

    return 0;
}
