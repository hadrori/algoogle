---
type: page
title: "座標圧縮"
comments: true
sharing: true
---

#### 基本情報
  
***

 | 
:--|:--
計算量 | 初期化 `$O(N \log N)$`, 圧縮 `$O(\log N)$`, 展開 `$O(1)$`
用途   | 座標を圧縮する
  
N := 圧縮する座標の数  

  
#### 解説

***

入力の個数に対して考えられる座標の範囲が広い時, 座標の大小関係を維持しつつ値の範囲を狭める.  
コードではzipで圧縮後の座標, unzipで圧縮前の座標を受け取る.  

#### コード

***

{{< includeCode "/algorithm/compress.cpp" "cpp" >}}


#### 問題

***  

