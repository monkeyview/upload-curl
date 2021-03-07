<?php
  require_once "Classes/PHPExcel.php";
  //$tmpfname = file_get_contents('php://input');
		$tmpfname = $_FILE;
		$excelReader = PHPExcel_IOFactory::createReaderForFile($tmpfname);
		$excelObj = $excelReader->load($tmpfname);
		$worksheet = $excelObj->getSheet(0);//
		$lastRow = $worksheet->getHighestRow();

		echo "<table>";
		for ($row = 1; $row <= $lastRow; $row++) {
			 echo "<tr><td>";
			 echo $worksheet->getCell('A'.$row)->getValue();
			 echo "</td><td>";
			 echo $worksheet->getCell('B'.$row)->getValue();
			 echo "</td><tr>";
		}
		echo "</table>";
  $_POST = json_decode($content, true);
  if(isset($_POST['name']) && isset($_POST['age'])) {
    echo $_POST['name'] . " " . $_POST['age'];
  }
?>
