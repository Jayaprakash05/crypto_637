cat input_commands.txt input.txt | sshpass -p cs641 ssh -tt student@172.27.26.188 | tee -a out.txt
