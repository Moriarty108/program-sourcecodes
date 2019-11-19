echo '--> Removing previous Dependencies...'
sudo rm -rvf ../test ../test.war
jar -cvf test.war *
echo '--> Copying the war package...'
cp -v test.war ../