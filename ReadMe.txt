━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

  色々な再起動の見本キャラクター
                              author:Halkaze

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

このキャラクターはCMDOFを用いて、選択されたカラーによって異なる
方法で再起動を試みるキャラクターです。

defファイルが二つ存在していますが、select.defには
「RebootKFM.def」の方を登録するようにしてください。

再起動後は1P、2Pとも.defを参照しています。.defは2P側にいるときには
自殺するので、.def同士の戦いは必ず1Pが勝利します。


なお、初期設定では選択時に再起動を行いますが、
「RebootKFM.def」内の設定項目にて、RETRET式コード実行により、
試合開始時に再起動を行うようにすることも可能です。


・不具合報告などはこちらまでどうぞ
    ブログ ：https://halkaze.fc2.net/
    Twitter：@halkazeMUGEN1

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

・カラー差

使用する関数は異なりますが、特にどれが強いとかは無いと思います。
強いて言えば、6Pが一番強いのかもしれませんが、結局は相手次第です。

カラー     使用する関数
 1P   ： WinExec
 2P   ： ShellExecuteA
 3P   ： ShellExecuteExA
 4P   ： CreateProcessA
 5P   ： CreateProcessInternalA
 6P   ： NtCreateUserProcess
 7P   ： RtlCreateUserProcess
 8P   ： ShellExecuteW
 9P   ： ShellExecuteExW
10P   ： CreateProcessW
11P   ： CreateProcessInternalW
12P   ： RtlCreateUserProcessEx

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

・更新履歴

2022/09/15: 公開
     11/05: ReadMeの誤記を修正
            環境次第で6Pが落ちていた不具合を修正

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
