from django.db import models


class Archivo(models.Model):
    n = models.CharField(max_length = 4)
    file_to_send = models.FileField(upload_to='Archivos')
    

