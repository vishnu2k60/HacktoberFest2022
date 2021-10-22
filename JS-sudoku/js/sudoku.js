$(document).ready(function() {	
	//loops through board and finds pre-populated cells and locks them
	$('input').each(function() {
		var prePopVal = $(this).val();
		if (prePopVal > 0) {
			$(this).addClass('prepopulated').attr('disabled','disabled');
		} else {
			$(this).addClass('playable');	
		}
	});	
	//Prevents you from entering anything other than a number between 1-9
	$('input').keyup(function(e) {
	    $(this).val($(this).val().replace(/[^1-9\.]/g,''));
	    var val = $(this).val();
	    var valLength = val.length;
	    var maxCount = $(this).attr('maxlength');
	    if(valLength>maxCount){
	        $(this).val($(this).val().substring(0,maxCount));
	    }
	    $(this).blur();
	});
	//"how Am I doing?" Button, fires the row, column and sector checkers
	$('.checkit').click(function() {	
		checkRows();
		checkColumns();
		checkSectors();
	});
	//"Complete game" Button: First checks to see if all the cells are filled, then checks for duplicates
	$('.completegame').click(function() {
	    var empty = $('input').filter(function() {
	        return this.value === '';
	    });
	    if(empty.length) {
		    $('.notfilled').show();
		    setTimeout( function() {
				$('.notfilled').fadeOut();			
			}, 1000 );
	    } else {
		    $('.notfilled').hide();
	        checkRows();
			checkColumns();
			checkSectors();
			if(!$('.error').hasClass('banana')) {
				$('.completed').show();
			}
	    }				
	});
	//Row Checker function, fires the dupes(); function for all rows
	var checkRows = function(sectionToCheck) {
		$('.keyrow').each(function() {
			var thisRow = $(this).attr('class').split(' ')[1];
			var sectionToCheck = '.'+thisRow;
			dupes(sectionToCheck);
		});		
	}
	//Column Checker function, fires the dupes(); function for all columns
	var checkColumns = function(sectionToCheck) {
		$('.keycolumn').each(function() {
			var thisColumn = $(this).attr('class').split(' ')[2];
			var sectionToCheck = '.'+thisColumn;
			dupes(sectionToCheck);
		});	
	}
	//Sector Checker function, fires the dupes(); function for all sectors
	var checkSectors = function(sectionToCheck) {
		$('.keysector').each(function() {
			var thisSector = $(this).attr('class').split(' ')[0];
			var sectionToCheck = '.'+thisSector;
			dupes(sectionToCheck);
		});	
	}
	//This is the main function that looks for all dupes in columns, rows and sectors
	var dupes = function(sectionToCheck) {
		var sectionValues = [];
		var sectionValues = $(sectionToCheck).map(function() {
			return this.value;
		}).get();
		sectionValues = sectionValues.filter(Number);
		function hasDuplicate(arr) {
		    var i = arr.length, j, val;
		
		    while (i--) {
		    	val = arr[i];
		    	j = i;
		    	while (j--) {
		    		if (arr[j] === val) {
		    			return true;
		    		}
		    	}
		    }
		    return false;
		}
		if (hasDuplicate(sectionValues)) {
			$('.error').addClass('banana').show();
			$('.ok').hide();
			$('.completed').hide();
			$(sectionToCheck).addClass('inerror');	
			setTimeout( function() {
				$(sectionToCheck).removeClass('inerror');
				$('.error').removeClass('banana').fadeOut();			
			}, 2000 );
		} else {
			if(!$('.error').hasClass('banana')) {
				$('.ok').show();
			}
			setTimeout( function() {
				$('.ok').fadeOut();			
			}, 2000 );

		}
	}	
});	