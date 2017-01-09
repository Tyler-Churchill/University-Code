

$( document ).ready(function() {

	var close = $('.close');

	$('#sun').on('click', function() {
		$('#sun-content').show();
	});

	$('#mercury').on('click', function() {
		$('#mercury-content').show();
	});

	$('#venus').on('click', function() {
		$('#venus-content').show();
	});


	$('#earth').on('click', function() {
		$('#earth-content').show();
	});


	$('#mars').on('click', function() {
		$('#mars-content').show();
	});

	close.on('click', function() {
		$('#sun-content').hide();
		$('#mercury-content').hide();
		$('#venus-content').hide();
		$('#earth-content').hide();
		$('#mars-content').hide();
	});

});