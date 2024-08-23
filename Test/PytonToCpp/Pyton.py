import random

numbers = '1234567890'
alphabet = 'abcdefghijklmnopkqrstuvwxyz'
up_alphabet = alphabet.upper()
mix_alph = alphabet + up_alphabet
digits = '*_-&₽#@%=/'

pasword = []

flag = True

num = False
up_alph = False
low_alph = False 
all_alph = False
digi = False

def alphabet_choice():
 for word in user_sug.lower().split():
  if 'мален' in word:
    low_alph = True
  if 'больш' in word:
    up_alph = True
  if 'раз' in word:
    all_alph = True
    
while flag == True:
 user_sug = input()
 
 for word in user_sug.lower().split():
  if word.isnumeric() == True:
   n = int(word)
  else:
   n = random.randint(10,21)
  if 'цифр' in word:
   num = True
  if 'букв' in word:
   for word in user_sug.lower().split():
    if 'мален' in word:
     low_alph = True
    if 'больш' in word:
     up_alph = True
    if 'раз' in word:
     all_alph = True

  if 'знак' in word:
   digi = True
  
  if 'стоп' in word:
   flag = False 

 while n > 0:
  if num:
   pasword.append(random.choice(numbers))
   n -= 1
  if up_alph:
   pasword.append(random.choice(up_alphabet))
   n -= 1
  if low_alph:
   pasword.append(random.choice(alphabet))
   n -=1
  if all_alph:
   pasword.append(random.choice(mix_alph))
   n -=1
  if digi:
   pasword.append(random.choice(digits))
   n -=1

 random.shuffle(pasword)
 final_pasword = ''.join(pasword)
 print(final_pasword)