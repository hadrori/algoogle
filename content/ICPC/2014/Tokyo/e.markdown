---
layout: post
title: "ACM-ICPC Tokyo Regional 2014 E Automotive Navigation"
date: 2014-10-24T03:06:00+09:00
comments: true
category: ICPC
tags: [implementation]
---

[Automotive Navigation](http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=ICPCOOC2014&pid=E)

#### 問題概要

****

x軸, y軸に平行な線分で繋がれたコースがある.  
今, 車のGPSが位置(x0, y0)で壊れた.  
以降単位時間毎にに前回の観測から移動した距離と現在の向いている向きを観測し報告する.  
向きは曲がり角にいる場合は曲る前と曲がった後のいずれかである.  
また車はUターンできない.  
時間tが経過したとき, 車の存在する場所としてありえる場所を列挙しろ.

#### 解法

****

問題の時間をターンということにする.  
各座標について上下左右に移動可能かを入力からつくる.  
あとは毎ターン距離dを移動させるのをBFSする.  
状態が増えすぎるとあれなので,(位置, 向き, そのターンでの移動距離)で既にチェック済みか記録しておく.  
次のターンの開始状態としてあり得るものを候補に列挙していく.  
向きが移動したあとというのは次のターンで移動距離1の状態ということでつくる.  
答えにするときは戻せばよい.

#### コード

****

{{< includeCode "/ICPC/2014/Tokyo/E.cpp" "cpp" >}}
