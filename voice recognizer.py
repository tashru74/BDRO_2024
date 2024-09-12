import speech_recognition as sr
import pyttsx3
from time import ctime
import webbrowser
import wikipedia as wiki

# Initialize the speech recognizer and text-to-speech engine
listener = sr.Recognizer()
engine = pyttsx3.init()
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)


def there_exists(terms, voice_data):
    for term in terms:
        if term in voice_data:
            return True
    return False


# Listen for audio and convert it to text
def record_audio(ask=False):
    with sr.Microphone() as source:
        if ask:
            speak(ask)

        audio = listener.listen(source)
        voice_data = ''
        try:
            voice_data = listener.recognize_google(audio)
        except sr.UnknownValueError:
            speak('I did not get that go and fuck your self nigga')
        except sr.RequestError:
            speak('Sorry, the service is down')
        print(f">> {voice_data.lower()}")
        return voice_data.lower()


# Convert text to speech
def speak(audio_string):
    engine.say(audio_string)
    engine.runAndWait()


def respond(voice_data):
    # Greeting
    if there_exists(['hey', 'hi', 'hello'], voice_data):
        speak("Hey, how can I help you sir?")

    # Check how the assistant is doing
    elif there_exists(["how are you", "what's up", "how are you doing"], voice_data):
        speak("I'm very well, thanks for asking sir.")
    elif there_exists(["tell me something about bushan","something about water city of bushan"], voice_data):
        speak("Busan South Korea is known as the City of Water for its stunning beaches like Haeundae and Gwangalli its busy port and vibrant maritime culture. The city combines beautiful coastal scenery with significant maritime activities making it a prominent coastal hub with a rich aquatic identity..")

    # Provide the current time
    elif there_exists(["what's the time", "tell me the time", "what time is it"], voice_data):
        current_time = ctime().split(" ")[3].split(":")[0:2]
        hours = '12' if current_time[0] == "00" else current_time[0]
        minutes = current_time[1]
        time_string = f'{hours}:{minutes}'
        speak(f'The current time is {time_string}.')

    # Search Google
    elif there_exists(["search for", "do you know",'what', 'how', 'why', 'which', 'where', 'when', 'tell me', 'who'], voice_data):
        search_term = voice_data.split("for")[-1].strip()
        url = f"https://google.com/search?q={search_term}"
        webbrowser.open(url)
        speak(f'Here is what I found for {search_term} on Google.')

    # Search YouTube
    elif there_exists(["play"], voice_data):
        search_term = voice_data.split("play")[-1].strip()
        url = f"https://www.youtube.com/results?search_query={search_term}"
        webbrowser.open(url)
        speak(f'Here is what I found for {search_term} on YouTube.')

    # Provide Wikipedia summary
    elif there_exists(['summarize', 'summarise'], voice_data):
        search_term = voice_data.split("summarize")[-1].strip()
        summary = wiki.summary(search_term, sentences=5)
        speak(summary)

    # elif there_exists(['what', 'how', 'why', 'which', 'where', 'when', 'tell me', 'who'], voice_data):
    #     search_term = voice_data.split(max(voice_data.split())).strip()
    #     summary = wiki.summary(search_term, sentences=6)
    #     speak(summary)

    # Exit the program
    elif there_exists(["exit", "quit", "goodbye"], voice_data):
        speak("Going offline")
        exit()


# Main loop
while True:
    voice_data = record_audio()
    respond(voice_data)
