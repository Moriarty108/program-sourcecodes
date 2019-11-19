sudo rm -R ../jdbcDemo
jar -cvf jdbcDemo.war *
sudo cp jdbcDemo.war ../
echo '\033[32m' Opening in Google Chrome
google-chrome http://localhost:8080/jdbcDemo/
echo '\033[34m' Note:If it shows 404,just refresh the browser 3-4 times '\033[39m'
