; ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
; ・optional.binのCMDOFで実行しているコードの内容

START:
SUB ESP, 0x4
PUSHAD

;
; code.binの処理がスキップされるように細工する
;
XOR EAX, EAX
MOV AX, 0x1F70
MOV ECX, DWORD [ESP+EAX]
MOV EDX, DWORD [0x4B5B4C]
MOV AX, 0xCD0
INC ECX
MOV EDX, DWORD [EDX+EAX]
MOV AX, 0xE30
IMUL ECX, EAX
ADD EDX, ECX
XOR EAX, EAX
MOV DWORD [EDX-0x4], EAX

POPAD
MOV EAX, DWORD [ESP]
MOV WORD [EAX], 0x22
MOV DWORD [ESI], EAX
PUSH 0x479B7B
RET


; ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
; ・optional.binのRETRET式で実行しているコードの内容

START:
;
; コード先頭アドレスを保存
MOV EBX, EAX

;
; スタックポインタを安全圏へ変更
;
MOV ESP, EAX

;
; DLLを読み込み
;
MOV EAX, EBX
ADD EAX, MODULENAME - START
PUSH EAX
MOV EAX, ~0x49F12C
NOT EAX
CALL DWORD [EAX]; LoadLibaryA
TEST EAX, EAX
JZ EXIT

;
; DLLの関数のアドレスを取得
;
MOV EDX, EBX
ADD EDX, FUNCNAME - START
PUSH EDX
PUSH EAX
MOV EAX, ~0x49F130
NOT EAX
CALL DWORD [EAX]; GetProcAddress
TEST EAX, EAX
JZ EXIT

;
; 関数に引数としてPalNoを与えて実行
;
PUSH 0x3B ; プレースホルダ、引数にてpalnoを埋め込み
CALL EAX

;
; 終了と同時にMUGENを落とす
;
EXIT:
XOR EAX, EAX
PUSH EAX
MOV EAX, ~0x49F0F0
NOT EAX
CALL DWORD [EAX]; ExitProcess

DB 0x5F
FUNCNAME:
DB "run@4"
DB 0

MODULENAME:
DB "./chars/RebootKFM/DLL/Reboot.dll"


; ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
