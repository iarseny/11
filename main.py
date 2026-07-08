import argostranslate.package
import argostranslate.translate

from_code = "en"
to_code = "ru"

argostranslate.package.update_package_index()
available_packages = argostranslate.package.get_available_packages()

package = next(
    filter(
        lambda x: True,
        available_packages
    )
)

argostranslate.package.install_from_path(package.download())

# Translate
txt = input()
translatedText = argostranslate.translate.translate(txt, from_code, to_code)
print(translatedText)
# '¡Hola Mundo!'