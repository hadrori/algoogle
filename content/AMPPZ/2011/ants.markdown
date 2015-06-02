---
layout: post
title: "AMPPZ 2011 Ants"
date: 2014-10-28T02:06:00+09:00
comments: true
category: AMPPZ
tags: [math]
---

[Ants](http://main.edu.pl/en/archive/amppz/2011/drz)

#### 問題概要

****

上を向いてる木がある(この木は木構造).  
この木の根の左右から2匹の蟻が進んでいく.  
左の蟻は上りに1辺1秒, 下りに1辺2秒かかる.  
右の蟻はその倍かかる.  
この蟻はぶつかると向きが反転する.  
地面にぶつかっても反転する.  
2回めに蟻が出会う時刻を有理数で求めよ.  
ただし入力の木は左側から上るか下るかの列を16進数で圧縮したもので与えられる(グラフを陽に保存するとMLEする).

#### 解法

****

AMPPZはPolish Collegiate Programming Contest.  
解法はLooking for a Challengeにあるのそのまま.  
ただ入力を1つづつ受け取るのが面倒+いらない部分を高速に読み飛ばすテクを知らない(そうしないとTLE)ということもあり入力をstringに突っ込んでいる.  
これをやるとジャッジではREになるが手元で合うので良しとした.

<div> $ {\displaystyle

f(a,h,t_{down},t_{up}) := 辺をa本辿って高さhになるのにかかる時間\\
f(a,h,t_{down},t_{up}) = \frac{a+h}{2}t_{down}+\frac{a-h}{2}t_{up}

} $</div>

ただしa, hは実数を許す.  
こうすると2匹が初めて出会う時刻について以下の式が成り立つ

<div> $ {\displaystyle

f(a_{1},h_{1},2,1) = f(2n-a_{1},h_{1},1,\frac{1}{2})

} $</div>

実数を扱うのはつらい.  
入力を順に読みながら辺ごとに進めていきたい.  
現在の辺をa, 高さをh, 上り下りかをbとする.  
辺上で中途半端に進んでいる場合, その割合をeとすると

<div> $ {\displaystyle

a_{1} = a+e\\
h_{1} = h+be

} $</div>

前の等式と合わせると

<div> $ {\displaystyle

e = \frac{6n-9a-h}{9+b}\\
t_{1} = \frac{3a_{1}+h_{1}}{2}

} $</div>

これが0以上1未満の場合, 1回目の出会いの辺にいることがわかる. tは時間  
左の蟻が次に地面にぶつかるのは同じ経路を戻るので辺と高さから整理すると

<div> $ {\displaystyle

f(a_{1},-h_{1},2,1) = t_{1}-h_{1}

} $</div>

1回目から2回目の邂逅までにかかる時間について同様に式を立てると

<div> $ {\displaystyle

a_2 = a+e\\
h_2 = h+be\\ 
f(a_{1},-h_{1},2,1)+f(2n-a_{2},h_{2},2,1) = f(a_{2}-a_{1},h_{2}-h_{1},1,\frac{1}{2})

} $</div>

よって

<div> $ {\displaystyle

e=\frac{12n-9(a-a_{1})+(h-h_{1})}{9-b}

} $</div>

となる. これが0以上1未満のとき, 2回目の出会いになる.  
あとは時間を計算すると

<div> $ {\displaystyle

t_{2}=\frac{3(a_{2}-a_{1})+(h_{2}-h_{1})}{4}\\
t_{1}+t_{2}=\frac{3(a_{1}+a_{2})+(h_{1}+h_{2})}{4}

} $</div>

#### コード

****

{{< includeCode "/AMPPZ/2011/ants.cpp" "cpp" >}}
