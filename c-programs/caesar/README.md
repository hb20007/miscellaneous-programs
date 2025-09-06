# Caesar Cipher

> Caesar cipher implementation in C

The program has four features:

* Encryption (`-e`)
* Decryption (`-d`)
* Brute force attack (`-a`)
* Brute force attack with known substring (`-a substring`)

## 1. Encryption

A key (right shift index) in the range [1, 25] must be specified.

```console
> caesar -e 12 "Get me a vanilla ice cream, make it a double."
Sqf yq m hmzuxxm uoq odqmy, ymwq uf m pagnxq.
```

## 2. Decryption

The key should be known and provided.

```console
> caesar -d 3 "Fdhvdu qhhgv wr orvh zhljkw."
Caesar needs to lose weight.
```

## 3. Brute force attack

Displays decryption of the given message with all possible keys.

```console
> caesar -a "Rdlpgsh sxt bpcn ixbth qtudgt iwtxg stpiwh."
Key: 1 Plaintext: Qckofrg rws aobm hwasg pstcfs hvswf rsohvg.
Key: 2 Plaintext: Pbjneqf qvr znal gvzrf orsber gurve qrnguf.
Key: 3 Plaintext: Oaimdpe puq ymzk fuyqe nqradq ftqud pqmfte.
Key: 4 Plaintext: Nzhlcod otp xlyj etxpd mpqzcp esptc oplesd.
Key: 5 Plaintext: Mygkbnc nso wkxi dswoc lopybo drosb nokdrc.
Key: 6 Plaintext: Lxfjamb mrn vjwh crvnb knoxan cqnra mnjcqb.
Key: 7 Plaintext: Kweizla lqm uivg bquma jmnwzm bpmqz lmibpa.
Key: 8 Plaintext: Jvdhykz kpl thuf aptlz ilmvyl aolpy klhaoz.
Key: 9 Plaintext: Iucgxjy jok sgte zosky hkluxk znkox jkgzny.
Key: 10 Plaintext: Htbfwix inj rfsd ynrjx gjktwj ymjnw ijfymx.
Key: 11 Plaintext: Gsaevhw hmi qerc xmqiw fijsvi xlimv hiexlw.
Key: 12 Plaintext: Frzdugv glh pdqb wlphv ehiruh wkhlu ghdwkv.
Key: 13 Plaintext: Eqyctfu fkg ocpa vkogu dghqtg vjgkt fgcvju.
Key: 14 Plaintext: Dpxbset ejf nboz ujnft cfgpsf uifjs efbuit.
Key: 15 Plaintext: Cowards die many times before their deaths.
Key: 16 Plaintext: Bnvzqcr chd lzmx shldr adenqd sgdhq cdzsgr.
Key: 17 Plaintext: Amuypbq bgc kylw rgkcq zcdmpc rfcgp bcyrfq.
Key: 18 Plaintext: Zltxoap afb jxkv qfjbp ybclob qebfo abxqep.
Key: 19 Plaintext: Ykswnzo zea iwju peiao xabkna pdaen zawpdo.
Key: 20 Plaintext: Xjrvmyn ydz hvit odhzn wzajmz oczdm yzvocn.
Key: 21 Plaintext: Wiqulxm xcy guhs ncgym vyzily nbycl xyunbm.
Key: 22 Plaintext: Vhptkwl wbx ftgr mbfxl uxyhkx maxbk wxtmal.
Key: 23 Plaintext: Ugosjvk vaw esfq laewk twxgjw lzwaj vwslzk.
Key: 24 Plaintext: Tfnriuj uzv drep kzdvj svwfiv kyvzi uvrkyj.
Key: 25 Plaintext: Semqhti tyu cqdo jycui ruvehu jxuyh tuqjxi.
```

## 4. Brute force attack with known substring

Decrypts a ciphertext with an unknown key when you know a word in the plaintext (case-sensitive).

```console
> caesar -a Brutus "Ymj kfzqy, ijfw Gwzyzx, nx sty ns tzw xyfwx, gzy ns tzwxjqajx."
Success! Key: 5, Plaintext: The fault, dear Brutus, is not in our stars, but in ourselves.
```
