<?php
    $no1 = range(99,9);
	$no2 = range(99,9);
	
	$ran1 = array_rand($no1);
	$ran2 = array_rand($no2);
	
	$n1 = $no1[$ran1];
	$n2 = $no2[$ran2];
	
	$cap = $n1."+" .$n2;
	$res = $n1 + $n2;
	
	if(isset($_POST['b1']))
	{
		 if($_POST['t2'] == $_POST['t3'])
		 {
			 echo "<font color ='blue' size = '5'> You are Welcome</font>";
		 }
		 else
		 {
			 echo "<font color = 'green' size = '5'> Enter Correct Answer</font>";
		 }
	}
?>
<html>
    <body>
	    <form method = "POST">
		    <center>
			    <?php echo $cap; ?>
				<input type = "hidden" name = "t3" value="<?php echo $res;?>"/>
				<input type = "text" name = "t2"/>
				<input type = "submit" name = "b1" value = "Match"/>
			</center>
		</form>
	</body>
</html>
	  
		