# Returns 1 for no and 0 for yes.
yesNo() {
    while :; do
        printf "[YES or NO]: "
        read answer
        case $answer in
            [yY] | [yY][eE][sS] ) return 0;;
            [nN]* ) return 1;;
            * ) echo 'Please type YES or NO.';;
        esac
    done
}

fold -s -w `tput cols`  NOTICE.txt
yesNo