function makeCanvas(){
	//get Object
	var canvas1 = document.getElementById('canvas1');
	var ctx1=canvas1.getContext('2d');

	//set Prop
	ctx1.font='30pt Arial';
	ctx1.fillStyle='DeepSkyBlue';
	ctx1.strokeStyle='black';

	//Action
	ctx1.fillText("I Love HTML",45,150);
	ctx1.strokeText("I Love HTML",47,152);


}
