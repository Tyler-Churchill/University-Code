

// horrible code ahead, turn back!

var currentSlide;
var index;
var slideCount = 5;
var htmlStyles = window.getComputedStyle(document.querySelector("html"));

$( document ).ready(function() {
    /**
    *       LANDING PAGE CODE
    *
    */
    $('[data-toggle=offcanvas]').click(function() {
            $('.row-offcanvas').toggleClass('active');
          });
  
    // loads in date selection curtains
    $(".main-content").load("curtains.html .curtains");

    //fade elements (visual effect)
    $(window).scroll(function(){
        $("#read-more").css("opacity", 1 - $(window).scrollTop() / 655);
        $("#top-bar").css("opacity", $(window).scrollTop() / 1250);
    });
    

      $('[data-toggle=offcanvas]').click(function() {
        $('.row-offcanvas').toggleClass('active');
    });


    $("#reference").on("click", function() {
        $(".main-content").load("references.html #ref");
    });

      $("#home").on("click", function() {
        $('.main-content').fadeOut('slow', function() {
                   $(".main-content").load("curtains.html .curtains", function() {
                  $('.main-content').fadeIn('slow');
             });
        });
    });


    // scrolls page to main content when read more clicked
    jQuery('#read-more').click(function(){
       $('html, body').animate({
        scrollTop: parseInt($(".main-content").offset().top)}, 1500);
    });

     jQuery('#top-bar a').click(function(){
       $('html, body').animate({
        scrollTop: parseInt($(".fullscreen:nth-child(1)").offset().top)}, 1500);
    });

    // display selected date's content
    $(".main-content").on("click", "#curtain", function() {
        index = $(this).index() + 1;
        currentSlide = index;
        $('.main-content').fadeOut('slow', function() {
             $(".main-content").load("timeline.html #date-slider", function() {
                  $('.main-content').fadeIn('slow');
             });
        });
    });


 });


$(document).ajaxComplete(function(){

       $("#reference").on("click", function() {
        $(".main-content").load("references.html #ref");
    });

      $("#home").on("click", function() {
        $('.main-content').fadeOut('slow', function() {
                   $(".main-content").load("curtains.html .curtains", function() {
                  $('.main-content').fadeIn('slow');
             });
        });
    });


    $("#date-slider li").on("click", function() {
        $('.main-content').fadeOut('slow', function() {
             $(".main-content").load("curtains.html .curtains", function() {
                  $('.main-content').fadeIn('slow');
             });
        });
    });


       /**
        *       TIMELINE SLIDER
        *
        */
        var slideWidth = $('#date-slider ul li').width();
        var slideHeight = $('#date-slider ul li').height();
        var sliderUlWidth = slideCount * slideWidth;
        $('#date-slider').css({ width: slideWidth, height: slideHeight });
        $('#date-slider ul').css({ width: sliderUlWidth, marginLeft: - slideWidth });
        $('#date-slider ul li:last-child').prependTo('#date-slider ul');
        $('.main-content').css('background', getBackgroundColor());
        moveTo();
     
        $('#date-slider ul').css('background', getBackgroundColor());
        $('#fullscreen:last-child').css('background', getBackgroundColor());

        function moveLeft() {
            currentSlide--;
            if(currentSlide <= 0)
                currentSlide = slideCount;
            $('#date-slider ul').animate({
                left: + slideWidth
            }, 200, function () {
                $('#date-slider ul li:last-child').prependTo('#date-slider ul');
                $('.main-content').css('background-color', getBackgroundColor());
                $('#date-slider ul').css('left', '').css('background', getBackgroundColor());
            });
                  console.log(currentSlide);
        };

        function moveRight() {
            currentSlide++;
            if(currentSlide > 5)
                currentSlide = 1;
            $('#date-slider ul').animate({
                left: - slideWidth
            }, 200, function () {
                $('#date-slider ul li:first-child').appendTo('#date-slider ul');
                $('.main-content').css('background-color', getBackgroundColor());
                $('#date-slider ul').css('left', '').css('background', getBackgroundColor());
               
            });
            console.log(currentSlide);
         
        };

        $('#date-slider').on("click", "a.control_prev", function () {
            moveLeft();
        });

        $('#date-slider').on("click", "a.control_next", function () {
            moveRight();
        });


        function moveTo() {
            var x = currentSlide;
            for(h = 1; h < x; h++)
                moveRight();
        }

        function getBackgroundColor() {
            var color = "#fff";
            switch (currentSlide) {
            case 1:
                color = htmlStyles.getPropertyValue("--dateOne");
                break;
            case 2:
                color = htmlStyles.getPropertyValue("--dateTwo");
                break;
            case 3:
                color = htmlStyles.getPropertyValue("--dateThree");
                break;
            case 4:
                color = htmlStyles.getPropertyValue("--dateFour");
                break;
            case 5:
                color = htmlStyles.getPropertyValue("--dateFive");
                break;
            default:
                return color;
            }
            return color;
        }


          $('[data-toggle=offcanvas]').click(function() {
            $('.row-offcanvas').toggleClass('active');
          });
   
});
