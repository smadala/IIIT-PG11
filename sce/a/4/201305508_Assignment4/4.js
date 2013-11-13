
function time() {
        var d=new Date();
        var weekdays=["Sunday","Monday","Tuesday","Wednesday", "Thursday","Friday","Saturday"];
        var months=[ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" ];
        formattedDate=weekdays[d.getDay()]+", "+months[d.getMonth()]
                +" "+d.getDate()+","+ d.getFullYear()+ " " +
                d.getHours()%12 + ":"+ (d.getMinutes()<10?"0"+d.getMinutes():d.getMinutes()) +
                " " + (d.getHours()>11?"pm":"am");

        document.getElementById("date").innerHTML=formattedDate;
}
