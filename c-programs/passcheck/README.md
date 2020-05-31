# Password Checker

> Password analyzer in C

Determines the strength of a given password. The features will be demonstrated below through examples with passwords of different strengths.

## 1. A password that is too popular

```console
$ passcheck abc123
Your password strength is VERY WEAK (COMMON PASSWORD).
It can be cracked instantly.

DETAILS
- Password: abc123
- Password length: 6 characters
- Charset size: 36 characters
- Entropy: 31.0 bits
- Advice: Try varying the case of letters, and including symbols..
```

The list of common passwords in [`commonPasswords.dat`](commonPasswords.dat) is used to check if the password inserted is too common.

## 2. A weak password

```console
$ passcheck jtz
Your password strength is WEAK.
It can be cracked in 0.001549 seconds on a core i5-6600K processor.

DETAILS
- Password: jtz
- Password length: 3 characters
- Charset size: 26 characters
- Entropy: 14.1 bits
- Advice: Try varying the case of letters, and including numbers and symbols..
```

## 3. A medium security-level password

```console
$ passcheck hsababa5
Your password strength is MEDIUM.
It can be cracked in 2 day(s) 21 hour(s) 4 minute(s) 33 second(s) on a core i5-6600K processor.

DETAILS
- Password: hsababa5
- Password length: 8 characters
- Charset size: 36 characters
- Entropy: 41.4 bits
- Advice: Try varying the case of letters, and including symbols..
```

## 4. A strong password

```console
$ passcheck f@AB12xY
Your password strength is STRONG.
It can be cracked in 17 year(s) 9 day(s) 17 hour(s) 32 minute(s) 13 second(s) on a core i5-6600K processor.

DETAILS
- Password: f@AB12xY
- Password length: 8 characters
- Charset size: 94 characters
- Entropy: 52.4 bits
- Advice: The password is fairly secure and skilled hackers may need good computing power to crack it.
Try making it longer for even extra security..
```

## 5. An ultra strong password

```console
$ passcheck 'F*f*23_fc@$(_132fdCD#$;aB@#GA!643'
Your password strength is STRONG.
Cracking this password would take hundreds of centuries on a core i5-6600K processor.

DETAILS
- Password: F*f*23_fc@$(_132fdCD#$;aB@#GA!643
- Password length: 33 characters
- Charset size: 94 characters
- Entropy: 216.3 bits
- Advice: The password is virtually impossible to crack. Often this level of security is overkill..
```

## Meta

H. Z. Sababa &mdash; hb20007 &mdash; hzsababa@outlook.com

Distributed under the MIT license. See `LICENSE.md` for more information.

https://github.com/hb20007
