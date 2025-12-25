import requests

# Public Joke API URL
url = "https://official-joke-api.appspot.com/random_joke"

# Sending a GET request to the API
response = requests.get(url)

# Converting the response to JSON
data = response.json()

# Printing the joke
print("Here's a random joke for you!")
print("Setup:", data['setup'])
print("Punchline:", data['punchline'])
