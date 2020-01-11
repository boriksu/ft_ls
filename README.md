# ft_ls
ft_ls is a project that aims to mimic the ls unix command

ft_ls manage the following flags `-l`, `-R`, `-a`, `-r`, `-t`, `-G`, `m`, `1` & `p`

Run `make`, usage : `./ft_ls [argv ...]`

##### Example of ft_ls:
```console
$> ./ft_ls -l 
total 160
drwxr-xr-x  166 dholiday  2019   5644 Jan 11 15:33 Libft
-rw-r--r--    1 dholiday  2019   1592 Jan 11 15:26 Makefile
-rw-r--r--    1 dholiday  2019     14 Jan 11 15:23 author
-rwxr-xr-x    1 dholiday  2019  62340 Jan 11 15:33 ft_ls
-rw-r--r--    1 dholiday  2019   4716 Jan 11 15:23 ft_ls.h
drwxr-xr-x   36 dholiday  2019   1224 Jan 11 15:33 src
```
