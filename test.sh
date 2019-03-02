clear
GRE='\033[0;33m'
NC='\033[0m'

echo "${GRE} Test 1 : ls \n${NC}"
sleep 1
./ft_ls
echo "${GRE}/\/\/\/\/\/\/\/\/\/\/\/\/\ ${NC}"
ls -1

echo "${GRE} End of Test\n${NC}"

read -n 1 -s -r -p "Press any key to continue"
###############################################

##############################################
clear 
echo "${GRE} Test 3 : ls -t -r \n${NC}"
sleep 1

./ft_ls -t -r
echo "${GRE}/\/\/\/\/\/\/\/\/\/\/\/\/\ ${NC}"
ls -tr1
echo "${GRE} End of Test\n${NC}"
read -n 1 -s -r -p "Press any key to continue"
###############################################

##############################################
clear 
echo "${GRE} Test 4 : ls -tral \n${NC}"
sleep 1

./ft_ls -tral
echo "${GRE}/\/\/\/\/\/\/\/\/\/\/\/\/\ ${NC}"
ls -tral
echo "${GRE} End of Test\n${NC}"
read -n 1 -s -r -p "Press any key to continue"
###############################################

##############################################
clear
echo "${GRE} Test 5 : ls -l /var \n${NC}"
sleep 1

./ft_ls -l /var
echo "${GRE}/\/\/\/\/\/\/\/\/\/\/\/\/\ ${NC}"
ls -l /var
echo "${GRE} End of Test\n${NC}"
read -n 1 -s -r -p "Press any key to continue"
###############################################

##############################################
clear 
echo "${GRE} Test 6 : ls -l /etc/ \n${NC}"
sleep 1

./ft_ls -l /etc/
echo "${GRE}/\/\/\/\/\/\/\/\/\/\/\/\/\ ${NC}"
ls -l  /etc/
echo "${GRE} End of Test\n${NC}"
read -n 1 -s -r -p "Press any key to continue"
###############################################

##############################################
clear 
echo "${GRE} Test 7 : ls -R \n${NC}"
sleep 1

./ft_ls -R
echo "${GRE}/\/\/\/\/\/\/\/\/\/\/\/\/\ ${NC}"
ls -tR1
echo "${GRE} End of Test\n${NC}"
read -n 1 -s -r -p "Press any key to continue"
