---
layout: page
title: "赤黒木(insert/delete)"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 |
insert | {% m %}O(\log N){% em %}
erase | {% m %}O(\log N){% em %}
空間 | {% m %}O(N){% em %}
用途 | set
  
N := 要素数  
  

#### 解説

***

平衡二分探索木として有名. std::setの実装にも使われている.  
赤黒木とは以下の5つの性質を満たすような2分木.  

* 節点の色は赤か黒
* 根は黒
* 葉は黒
* 赤の子は共に黒
* 節点からその任意子孫の葉までの経路に含まれる黒節点の数は等しい

実装はinsert/deleteベースでされている([赤黒木(merge/split)](/algorithm/rbtree_merge.html)).  
根の親と葉としてnilを使う.  
nilは1つ用意して流用する.  
実装の関係上NULLとかにするとアクセスしようとして死ぬ.  
  
ch\[2\]に左右の子を入れる.  
left, rightとかでやるとさらに場合分けがエグい.  
  
ノードに適当にデータをもたせればstd::mapっぽい感じになる.  
  
競技プログラミング的な用途としてはこれを永続化して使うことがあるかないか([永続赤黒木](/algorithm/prbtree.html)).  
そのままではstd::setの下位互換.  

#### コード

***

{% include_code algorithm/rbtree.cpp %}

