
<!doctype html>
<html lang="en">
<head>
	<meta charset="utf-8">
	<title>Remote controll RC Car</title>
	<link rel="stylesheet" href="//code.jquery.com/ui/1.11.4/themes/smoothness/jquery-ui.css">
  	<script src="//code.jquery.com/jquery-1.10.2.js"></script>
  	<script src="//code.jquery.com/ui/1.11.4/jquery-ui.js"></script>
  	<script>
	function setSpeed(speed) {
		$("#speed").slider('value', speed);
	}
	function updateSpeed() {
		var value = $("#speed").slider("value");
		$("#valueS").text(value);
		$.get("http://<ip>:8080/speed/"+value);
	}
  	$(function() {
    		$("#speed").slider( {
			value: 0,
			min: -100,
			max: 100,
            change: updateSpeed,
			animate: true
		});
  	})
  	</script>
</head>
<body>
<br>Set Speed</br>
<div id="speed"></div>
<div id="valueS">0</div>
</body>
</html>