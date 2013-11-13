function drawCanvas(){
          canvas = document.getElementById("main");
          var ctx = canvas.getContext("2d");
          ctx.fillStyle = "red";
	ctx.save();
        ctx.shadowColor="#000000";
	ctx.shadowBlur=3;
	ctx.shadowOffsetX=6;
	ctx.shadowOffsetY=6;
	ctx.shadowColor="black";
        ctx.font = "bold 55px sans-serif";
        ctx.fillText("HTML 5", 250, 165);
	ctx.restore();
        ctx.strokeRect(100,100,600,400);
		

          ctx.font = "italic 30px Arial";
          ctx.fillStyle = "black";
          ctx.fillText("This is in italic", 150, 220);
          ctx.fillStyle = "black";
          ctx.font = "bold 30px Arial";
          ctx.fillText("This is in bold", 150, 255);
          ctx.font = "bold italic 30px Arial";
          ctx.fillStyle = "black";
          ctx.fillText("This is in bold and italic", 150, 290);
          ctx.font = "bold italic 30px Arial";
          ctx.fillStyle = "green";
          ctx.fillText("This is in green", 150, 325);
          ctx.font = "bold italic 30px Arial";
          ctx.fillStyle = "purple";
          ctx.fillText("This is in purple", 150, 360);
          ctx.font = "bold 25px Arial";
          ctx.fillStyle = "#F1AB21";
          ctx.fillText("Canvas", 600, 500);

          ctx.rotate(100);
          ctx.beginPath();
          ctx.fillStyle="cyan";
          ctx.fillRect(35,138,200,50);
          ctx.fillStyle="white";
	  ctx.font = "bold italic 16px Arial";
          ctx.fillStyle="black";
          ctx.fillText("Scripting and computing", 40, 157);
          ctx.fillText("environment", 40, 180);
          
          ctx.fillStyle = "black";
          ctx.strokeRect(35,138,200,50);
}
