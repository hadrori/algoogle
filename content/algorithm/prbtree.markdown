---
type: page
title: "永続赤黒木"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 |
merge | `$O(\log N)$`
split | `$O(\log N)$`
insert | `$O(\log N)$`
build | `$O(M)$`
add | `$O(\log N)$`
空間 | `$O(N)$`
  
N := ノード数  
M := 生成元の列の長さ  

#### 解説

***

0から連続する整数をkeyとする赤黒木の永続版.  
merge/splitベースで書かれている([赤黒木(merge/split)](/algorithm/rbtree_merge.html)).  
[JOI 春合宿 2012 Day4 Copy and Paste](/JOI/sc2012copy-and-paste/)で使ったものをを元にしている.  
[解説スライド](http://www.ioi-jp.org/camp/2012/2012-sp-tasks/2012-sp-day4-copypaste-slides.pdf)  
  
* build: 列から木を生成する  
* add: 要素を後ろに追加する  
* get: 要素を左から順に並べた列をつくる  
* merge: 木の根同士をもってきてつなげる  
* split: k番目の要素で別れるように木を切る  
* insert: k番目に木を挿入する  
* copy: 区間に対応する部分木の根を取り出す  
  
versionとか持たせたいなら適当にcommit関数とか作ってそのときのrootを保存していけばよさそう(適当)

#### コード

***

{{< includeCode "/algorithm/prbtree.cpp" "cpp" >}}

