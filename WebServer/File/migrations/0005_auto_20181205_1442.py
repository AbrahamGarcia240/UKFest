# Generated by Django 2.1.3 on 2018-12-05 14:42

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('File', '0004_auto_20181205_1437'),
    ]

    operations = [
        migrations.RenameField(
            model_name='archivo',
            old_name='name',
            new_name='n',
        ),
    ]
