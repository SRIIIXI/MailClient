#include "MailBoxView.h"
#include "MailView.h"
#include "../network/Mail.h"
#include "../data/MailStorage.h"
#include "../utils/StringEx.h"
#include "../app/MailClient.h"

MailBoxView::MailBoxView(QWidget* parent) : RichDataList(true)
{
	setMaximumWidth(350);
	setMinimumWidth(350);

	mailViewPtr = nullptr;
	currentViewItem = nullptr;

	auto c = connect(this, &QListWidget::itemClicked, this, &MailBoxView::eventMailSelected);
}

MailBoxView::~MailBoxView()
{
}

void MailBoxView::Initialize(MailView* ptr)
{
	mailViewPtr = ptr;
}

void MailBoxView::eventMailSelected(QListWidgetItem* item)
{
	currentViewItem = item;

	std::string currUID = currentViewItem->data(Qt::UserRole + 1).toString().toStdString();

	if (mailLookup.find(currUID) != mailLookup.end())
	{
		if (mailViewPtr != nullptr)
		{
			currentToken = mailLookup[currUID];
			emit MailSelected(currentToken);
            std::string account = currentToken.GetHeaderValue("Account");
            std::string directory = currentToken.GetHeaderValue("Directory");
            std::string uid = currentToken.GetHeaderValue("UID");
            mailClientPtr->MarkEmailSeen(account, directory, uid);
			item->setData(Qt::UserRole + 2, QVariant(false));
			update();
		}
	}
}

void MailBoxView::eventClearMailView()
{
	clear();
	mailLookup.clear();
	currentViewItem = nullptr;
}

void MailBoxView::eventMailListReceived(std::vector<MailHeader>& mlist)
{
	clear();
	mailLookup.clear();
	currentViewItem = nullptr;

	int count = mlist.size();

	for (int index = 0; index < count; index++)
	{
		HeaderReceived(mlist[index]);
	}
}

void MailBoxView::HeaderReceived(MailHeader emlhdr)
{
	std::string temp_timestamp = emlhdr.GetTimeStamp();

	size_t tz_str_pos = std::string::npos;

	tz_str_pos = temp_timestamp.find('+');

	if (tz_str_pos == std::string::npos)
	{
		tz_str_pos = temp_timestamp.find('-');
	}

	if (tz_str_pos != std::string::npos)
	{
		temp_timestamp = temp_timestamp.erase(tz_str_pos, temp_timestamp.length() - tz_str_pos);
	}

	if (mailLookup.find(emlhdr.GetMessageId()) == mailLookup.end())
	{
		QString subject = emlhdr.GetSubject().c_str();
		if (subject.toLower().contains("utf-8"))
		{
			subject = QString::fromUtf8(emlhdr.GetSubject().c_str());
		}		
		
		QString description;
		description += emlhdr.GetFrom().c_str();
		description += ", ";
		description += temp_timestamp.c_str();

		QListWidgetItem* mailItem = new QListWidgetItem(this);
		mailItem->setData(Qt::DisplayRole, QVariant(subject));
		mailItem->setData(Qt::UserRole, QVariant(description));
		mailItem->setData(Qt::UserRole + 1, QVariant(emlhdr.GetHeaderValue("UID").c_str()));

		mailLookup[emlhdr.GetHeaderValue("UID")] = emlhdr;
	}
}

void MailBoxView::DeleteCurrent()
{
	if (currentViewItem == nullptr)
	{
		return;
	}

	std::string currUID = currentViewItem->data(Qt::UserRole + 1).toString().toStdString();

	if (mailLookup.find(currUID) != mailLookup.end())
	{
		if (mailViewPtr != nullptr)
		{
			currentToken = mailLookup[currUID];
		}
	}

    std::string account = currentToken.GetHeaderValue("Account");
    std::string directory = currentToken.GetHeaderValue("Directory");
    std::string uid = currentToken.GetHeaderValue("UID");
    std::string messageid = currentToken.GetMessageId();

    if (mailClientPtr->RemoveEmail(account, directory, uid, messageid))
	{
		removeItemWidget(currentViewItem);
		delete currentViewItem;
		currentViewItem = nullptr;
	}
}

void MailBoxView::FlagCurrent()
{
	if (currentViewItem == nullptr)
	{
		return;
	}

	std::string currUID = currentViewItem->data(Qt::UserRole + 1).toString().toStdString();

	if (mailLookup.find(currUID) != mailLookup.end())
	{
		if (mailViewPtr != nullptr)
		{
			currentToken = mailLookup[currUID];
		}
	}

	std::string flag = "Flagged";

    std::string account = currentToken.GetHeaderValue("Account");
    std::string directory = currentToken.GetHeaderValue("Directory");
    std::string uid = currentToken.GetHeaderValue("UID");
    std::string messageid = currentToken.GetMessageId();

    if (mailClientPtr->FlagEmail(account, directory, uid, flag))
	{

	}
}

void MailBoxView::MarkAsSeenCurrent()
{
	if (currentViewItem == nullptr)
	{
		return;
	}

	std::string currUID = currentViewItem->data(Qt::UserRole + 1).toString().toStdString();

	if (mailLookup.find(currUID) != mailLookup.end())
	{
		if (mailViewPtr != nullptr)
		{
			currentToken = mailLookup[currUID];
		}
	}

    std::string account = currentToken.GetHeaderValue("Account");
    std::string directory = currentToken.GetHeaderValue("Directory");
    std::string uid = currentToken.GetHeaderValue("UID");
    std::string messageid = currentToken.GetMessageId();

    mailClientPtr->MarkEmailSeen(account, directory, uid);
}

void MailBoxView::MoveToNext()
{
	if (currentViewItem == nullptr)
	{
		return;
	}
}

void MailBoxView::MoveToPrevious()
{
	if (currentViewItem == nullptr)
	{
		return;
	}
}

MailHeader MailBoxView::GetCurrentToken()
{
	return currentToken;
}
