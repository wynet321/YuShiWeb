<?
function get_hit($counter_file) {
	if (! isset ( $_COOKIE ['count'] )) {
		if (file_exists ( $counter_file )) {
			$fp = fopen ( $counter_file, "rw" );
			$count = 1 + fgets ( $fp, 20 );
			fputs ( $fp, $count );
			fclose ( $fp );
		} else {
			$fp = fopen ( $counter_file, "w" );
			fputs ( $fp, $count );
			fclose ( $fp );
		}
		setcookie ( 'count', $count, time () + 30 );
	} else {
		$count = $_COOKIE ['count'];
	}
	return ($count);
}
function get_div_location($url, $name) {
	echo "<div id=\"location\">
	<span>当前位置：</span>&nbsp;&nbsp;<a href=\"/index.html\">网站首页</a>&nbsp;&nbsp;&gt;&nbsp;&nbsp;<a
	href=\"" . $url . "\">" . $name . "</a>
	</div>";
}