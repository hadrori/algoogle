---
layout: page
title: "スライド最小値"
comments: true
sharing: true
---
  
#### 基本情報
  
***

計算量 | {% m %}O(1){% em %}
  
#### 解説

***

区間の最小値を求める(同様にして最大値もできる).  
幅を固定して列を舐めるときに有効な手法.  
幅を固定しなくてもしゃくとりなど区間の両端の位置が単調非減少に推移するときに有効.  
  
数列を左から右に舐めるのを考える.  
dequeに値の位置を突っ込んでいく.  
dequeのfrontに常に区間の最小値のうち一番後の位置が入るようにする.  
区間の右端を進めるとき, 新しい値以上の位置があるとき後ろからそれらを全部popしていく.  
その後, 右端の位置を入れる.  
区間の左端を進めるときはfrontの位置が範囲外になるならpopする.  
  
コードは幅wの区間を左からみて最小値を列挙する.

#### コード

{% include_code algorithm/slide-min.cpp %}


#### 問題

***  

{% for post in site.tags['slide-min-max'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
