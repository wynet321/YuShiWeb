<?
function getHit($counter_file) {
	if (! isset ( $_COOKIE ['count'] )) {
		if (file_exists ( $counter_file )) {
			$fp = fopen ( $counter_file, "r+" );
			$count = fgets ( $fp ) + 1;
			fputs ( $fp, $count );
			fclose ( $fp );
		} else {
			$count = 1;
			$fp = fopen ( $counter_file, "w" );
			fputs ( $fp, 1 );
			fclose ( $fp );
		}
		setcookie ( 'count', $count );
	} else {
		$count = $_COOKIE ['count'];
	}
	return ($count);
}
function getDivLocation($url, $name) {
	echo "<div id=\"location\">
	<span>当前位置：</span>&nbsp;&nbsp;<a href=\"/index.html\">网站首页</a>&nbsp;&nbsp;&gt;&nbsp;&nbsp;<a
	href=\"" . $url . "\">" . $name . "</a>
	</div>";
}
function getNewsArray($folder, $seqId) {
	if ($seqId != null && $seqId > 0 && $seqId < 6 && file_exists ( $folder . $seqId . ".txt" )) {
		$fp = fopen ( $folder . $seqId . ".txt", "r" );
		$time = iconv ( "GBK", "UTF-8", fgets ( $fp ) );
		$title = iconv ( "GBK", "UTF-8", fgets ( $fp ) );
		$content = "";
		while ( ! feof ( $fp ) ) {
			$content = $content . iconv ( "GBK", "UTF-8", fgets ( $fp ) ) . "<br>";
		}
		$arrayResult = array (
				"title" => $title,
				"time" => $time,
				"content" => $content 
		);
		return $arrayResult;
	} else
		echo "No result!";
}
function getTitleArray($category) {
	for($i = 1; $i < 21; $i ++) {
		if (! file_exists ( "../" . $category . "/" . $i . ".txt" )) {
			file_put_contents ( "../" . $category . "/" . $i . ".txt", "" );
			$newsTitleArray [$i] = "";
		} else {
			$fp = fopen ( "../" . $category . "/" . $i . ".txt", "r" );
			fgets ( $fp );
			$newsTitleArray [$i] = iconv ( "GBK", "UTF-8", fgets ( $fp ) );
			fclose ( $fp );
		}
	}
	return $newsTitleArray;
}