# PDF book Reader
This is a desktop program built in Python that reads text from PDF files and converts it to speech.
The user selects a file in a UI window to add to the list of files to be played.

### Prerequisites

Python 3

```
If you don't have python install on your system, download it from 'https://www.python.org/downloads'
make sure it's added to PATH
```

### Installing

Creata a virtual environment
> python -m venv env

Activate virtual environment
> env\Scripts\activate

Upgrade Pip
To upgrade to the latest version of pip run the following command
> python -m pip install --upgrade pip

install requirements
> python -m pip install -r requirements

Usage
> python main.py

Once the app loads it will open a GUI window where you can select a book to listen to.

 
# Built With
* [Tkinter] - The GUI library
* [PyPDF2] - Used to Read PDF files
* [pyttsx3] - Used to convert text to speech

## Authors

* **Peter S. Zyambo** - *Initial work* - [sangwani-coder](https://github.com/sangwani-coder)

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments
* Inspiration
* Harvard's cs50 staff
* David J. Malan

