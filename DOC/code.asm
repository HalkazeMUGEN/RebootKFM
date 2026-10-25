; ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
; ・code.binのCMDOFで実行しているコードの内容

START:
SUB ESP, 0x4
PUSHAD

;
; コード先頭アドレスを取得
;
PUSH 0x909090C3
CALL ESP
RETURN:
ADD ESP, 0x4
MOV EBX, DWORD [ESP-0x8]
; EBX := コード先頭アドレス
SUB EBX, RETURN - START

;
; 自身のPalNoを取得
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
MOV EDX, DWORD [EDX-0x4]
TEST EDX, EDX
JZ END
NOT EDX
BSF ESI, EDX
; ESI := PalNo
INC ESI

;
; DLLを読み込み
;
MOV EAX, EBX
ADD EAX, MODULENAME - START
PUSH EAX
CALL DWORD [0x49F12C]; LoadLibaryA
TEST EAX, EAX
JZ EXIT

;
; DLLの関数のアドレスを取得
;
MOV EDX, EBX
ADD EDX, FUNCNAME - START
PUSH EDX
PUSH EAX
CALL DWORD [0x49F130]; GetProcAddress
TEST EAX, EAX
JZ EXIT

;
; 関数に引数としてPalNoを与えて実行
;
PUSH ESI
CALL EAX

;
; 終了と同時にMUGENを落とす
;
EXIT:
PUSH 0
CALL DWORD [0x49F0F0]; ExitProcess

DB 0x5F
FUNCNAME:
DB "run@4"
DB 0

MODULENAME:
DB "./chars/RebootKFM/DLL/Reboot.dll"
DB 0

;
; optional読み込み時は復帰させる
;
END:
POPAD
MOV EAX, DWORD [ESP]
MOV WORD [EAX], 0x22
MOV DWORD [ESI], EAX
PUSH 0x479B7B
RET


; ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
