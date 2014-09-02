<?php
header ( 'Content-Type: text/html; charset=utf-8' );
if (isset ( $_GET ['add'] )) {
	// add new
	if (file_exists ( "../" . $_REQUEST ["category"] . "/20.txt" ))
		unlink ( "../" . $_REQUEST ["category"] . "/20.txt" );
	for($i = 1; $i < 21; $i ++) {
		rename ( "../" . $_REQUEST ["category"] . "/" . (20 - $i) . ".txt", "../" . $_REQUEST ["category"] . "/" . (21 - $i) . ".txt" );
	}
	file_put_contents ( "../".$_REQUEST ["category"]."/1.txt", "" );
	
	header ( 'Refresh: 0;URL=manage.html' );
} else {
	// upload
	if ($_FILES ["file"] ["error"] > 0) {
		echo "Error: " . $_FILES [$_REQUEST ["category"] ."file"] ["error"] . "<br>";
	} else {
		echo "Upload: " . $_FILES [$_REQUEST ["category"] ."file"] ["name"] . "<br>";
		echo "Type: " . $_FILES [$_REQUEST ["category"] ."file"] ["type"] . "<br>";
		echo "Size: " . ($_FILES [$_REQUEST ["category"] ."file"] ["size"] / 1024) . " kB<br>";
		echo "Stored in: " . $_FILES [$_REQUEST ["category"] ."file"] ["tmp_name"];
		$newsFileName = "../" . $_REQUEST ["category"] . "/" . $_POST ['list'] . ".txt";
		if (move_uploaded_file ( $_FILES [$_REQUEST ["category"] ."file"] ["tmp_name"], $newsFileName ))
header ( 'Refresh:0;URL=manage.html' );
		else
			echo "Error: " . $newsFileName . " upload fail!";
	}
}



