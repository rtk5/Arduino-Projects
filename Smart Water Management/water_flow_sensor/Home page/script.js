document.addEventListener('DOMContentLoaded', function() {
    console.log("Document ready. Attempting to fetch location.");
    navigator.geolocation.getCurrentPosition(success, error);

    function success(position) {
        const lat = position.coords.latitude;
        const lon = position.coords.longitude;
        console.log(`Location acquired: ${lat}, ${lon}`);
        fetchWeatherAndLocation(lat, lon);
    }

    function error() {
        console.log("Unable to retrieve your location");
    }

    function fetchWeatherAndLocation(lat, lon) {
        const apiKey = 'e5ff05f28245587b9e475f1b56ec8807'; 
        console.log("Fetching weather...");
        fetch(`https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&appid=${apiKey}&units=metric`)
            .then(response => {
                if (!response.ok) {
                    throw new Error(`HTTP error! status: ${response.status}`);
                }
                return response.json();
            })
            .then(data => {
                console.log("Weather data:", data);
                if (data && data.main && data.main.temp) {
                    document.getElementById('weather').textContent = `${data.main.temp}°C`;
                    document.getElementById('location').textContent = `${data.name}`;
                } else {
                    console.error("Weather data is incomplete:", data);
                }
            }).catch(error => console.error("Error fetching weather data:", error));

        const now = new Date();
        const hour = now.getHours();
        const greeting = 'Water Management System';
        document.getElementById('greeting').textContent = greeting;
    }
});
