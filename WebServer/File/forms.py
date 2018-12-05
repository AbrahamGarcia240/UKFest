from django import forms
from django.core.exceptions import ValidationError
import File.models as m

class GetFile(forms.ModelForm):
    class Meta:
        model = m.Archivo
        fields = '__all__'
