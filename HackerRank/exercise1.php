<?php 

function solveMeFirst() {
    
$file = @fopen("file.txt", "r");
echo fgets($file,10);
fclose($file);

}
solveMeFirst();
?>