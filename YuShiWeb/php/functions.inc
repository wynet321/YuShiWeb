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
		$time = fgets ( $fp );
		$title = fgets ( $fp );
		$content = "";
		while ( ! feof ( $fp ) ) {
			$content = $content . fgets ( $fp ) . "<br>";
		}
		$array_result = array (
				"title" => $title,
				"time" => $time,
				"content" => $content 
		);
		return $array_result;
	} else
		echo "No result!";
}