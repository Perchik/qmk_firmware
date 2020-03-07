line='''
KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
'''

rows = [
# Length preformat
(7, '/**Left Hand */\n'),
(7, ''),
(6, ''),
(7, ''),
(5, ''),
(2, '\n' +' '*50 ),
(1, ' '*60),
(3, ' '*40),

(7, '\n/**Right Hand */\n'),
(7, ''),
(6, ''),
(7, ''),
(5, ' '*10),
(2, '\n'  ),
(1, ''),
(3, '')
]

f = open('output.txt','w')
keys = line.split(',')
output = ''
width, pre = rows.pop(0)
count = 0
output += pre
for key in keys:
    k = key.strip() +','
    k = k.ljust(10)
    output += k 
    count +=1
    if count == width:
        output += '\n'
        if len(rows):
            width, pre = rows.pop(0)
            count=0
            output += pre

f.write(output)
f.close()