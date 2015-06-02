---
layout: page
title: "剰余"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量(除算) | {% m %}O(\log m){% em %}
計算量(pow) | {% m %}O(\log k){% em %}
計算量(それ以外) | {% m %}O(1){% em %}
用途 | modをとる
    
m := 除算で使われる値のうち小さい方  
k := 指数  

#### 解説

***

除算では毎回逆元を求めている.  
除算を多用する場合は予め逆元の列を求めておくほうがよい


#### コード 

***

{% include_code algorithm/mint.cpp %}

