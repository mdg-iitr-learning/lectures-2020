# Bandit Solutions(Level 0-15)

## Level 0
Run `ssh bandit0@bandit.labs.overthewire.org  -p  2220` and enter the given password on website i.e. `bandit0`.

## Level 0-1
`cat readme` will give the password for the next level
password - **boJ9jbbUNNfktd78OOpsqOltutMc3MY1**

## Level 1-2
`cat ./-` will give the password for the next level
password - **CV1DtqXWVFXTvM2F0k09SHz0YwRINYA9**

## Level 2-3
`cat spaces\ in\ this\ filename` will give the password for the next level
password - **UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK**

## Level 3-4
  
```
cd inhere/
ls -la
cat .hidden
``` 
password - **pIwrPrtPN36QITSp3EQaw936yaFoFgAB**

## Level 4-5

```
cd inhere/
ls -a
file ./-*
cat ./-file07
```
password - **koReBOKuIDDepwhWk7jZC0RTdopnAYKh**

## Level 5-6
```
find -readable –size 1033c ! -executable
cat ./maybehere07/.file2
```
password - **DXjZPULLxYr17uwoI01bNLQbtFemEgo7**

## Level 6-7
```
cd /
find -group bandit6 -user bandit7  -size  33c
cat /var/lib/dpkg/info/bandit7.password
```
password - **HKBPTKQnIay4Fw76bEy8PVxKEDQRKTzs**

## Level 7-8
```
cat data.txt | grep millionth
```
password - **cvX2JJa4CFALtqS87jk27qwqGhBM9plV**

## Level 8-9
```
cat data.txt | sort | uniq -u
```
password - **UsvVyFSfZZWbi6wgC7dAFyFuR6jQQUhR**

## Level 9-10
```
strings data.txt | grep =
```
password - **truKLdjsbJ5g7yyJ2X2R0o3a5HQJFuLk**

## Level 10-11
```
base64 --decode data.txt
```
password - **IFukwKGsFW8MOq3IRFqrxE1hxTNEbUPR**

## Level 11-12
```
cat data.txt | tr a-zA-Z n-za-mN-ZA-M
```
Can be done by using online rot13 decoder
password - **5Te8Y4drgCRfCx8ugdwuEX8KFC6k2EUu**

## Level 12-13
Here we have to decompress files many times to get the password. It teaches gzip, bzip and tar files decompression.
password - **8ZjyCRiBWFYkneahHwxCv3wb2a1ORpYL**

## Level 13-14
```
ssh bandit14@localhost -i ./sshkey.private
```
We go directly to bandit 14

## Level 14-15
```
cat  /etc/bandit_pass/bandit14
telnet localhost  30000
4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e
```
password - **BfMYroe26WYalil77FoDi9qh59eK5xNr**
