def encrypt(text, key):
    res = ''
    for c in text:
        if c.isalpha():
            base = 65 if c.isupper() else 97
            res += chr((ord(c) + key - base) % 26 + base)
        else:
            res += ' '
    return res

def decrypt(text, key):
    return encrypt(text, -key)

text = "Simple but good"
key = 13

cipher = encrypt(text, key)
print("Encrypted:", cipher)
print("Decrypted:", decrypt(cipher, key))

# Frequency 